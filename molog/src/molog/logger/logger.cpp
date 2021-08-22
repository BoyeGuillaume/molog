/**
 * @file logger.cpp
 * @author Guillaume Boyé
 * @version 0.1.4
 * @date 2021-08-21
 * 
 * @copyright MIT License
 * Copyright (c) 2021 Guillaume Boyé
 * 
 */

#include "logger.hpp"
#include <thread>
#include <type_traits>
#include <algorithm>
#include <ctime>

#include <molog/exception.hpp>
#include <molog/assertion.hpp>

MO_USE_NAMESPACE;



MO_FUNCTION LogEntry::LogEntry(Logger* logger, LogContext&& context) MO_NOEXCEPT
    : m_logger(logger),
    m_context(context),
    m_formatting(true),
    m_entries()
{

}

MO_FUNCTION LogEntry::~LogEntry()
{
    m_logger->_log(std::move(m_entries), std::move(m_context), m_formatting);
}

MO_FUNCTION LogEntry& LogEntry::operator<<(LogFlag flag)
{
    if(flag == NoFormatting) {
        m_formatting = false;
    }
    return *this;
}

MO_FUNCTION LogEntry& LogEntry::operator<<(PipeFlag flag)
{
    m_entries.push_back(entry_t(flag));
    return *this;
}

MO_FUNCTION LogEntry& LogEntry::operator<<(const std::string& str)
{
    m_entries.push_back(entry_t(str));
    return *this;
}



MO_FUNCTION Logger::Logger(std::shared_ptr<OPipe> pipe, std::unique_ptr<formatter_t> formatter)
    : m_pipe(pipe),
    m_formatter(std::move(formatter))
{
    MO_ASSERT_NON_NULL(m_pipe, "Logger::Logger require a valid pipe handle");
    MO_ASSERT_NON_NULL(m_formatter, "Logger::Logger require a formatter handle");
}

MO_FUNCTION Logger::~Logger()
{

}

MO_FUNCTION LogEntry Logger::log(Severity severity)
{
    LogEntry::LogContext ctx { severity };
    return LogEntry(this, std::move(ctx));
}

MO_FUNCTION void Logger::_log(std::list<LogEntry::entry_t>&& entries, LogEntry::LogContext&& context, bool _formatting)
{
    const std::lock_guard<std::mutex> lock(m_lock);
    
    if(_formatting) m_formatter->init(m_pipe, std::move(context));
    std::for_each(entries.begin(), entries.end(), [this,_formatting](const LogEntry::entry_t& entry) {
        std::visit([this,_formatting](auto&& arg) {
            using T = std::decay_t<decltype(arg)>;

            if constexpr(std::is_same_v<T, std::string>)
            {
                if(_formatting) this->m_formatter->log(arg);
                else this->m_pipe->write(arg.data(), arg.size());
            }
            else if constexpr (std::is_same_v<T, PipeFlag>)
            {
                if(_formatting) this->m_formatter->log(arg);
                else this->m_pipe->write(arg);
            }
#ifdef MOLOG_VALIDATION_LAYER
            else
            {
                MO_THROW_EXCEPTION("InvalidStateException: the given element type in the variant ain't supported");
            }
#endif

        }, entry);
    });
    if(_formatting) this->m_formatter->finalize();
}


struct MO_CLASS default_formatter : public Logger::formatter_t
{
    const uint_t m_alignedColOffset;
    const uint_t m_maxColWidth;
    const std::function<std::string(LogEntry::LogContext)> m_prefix;
    std::shared_ptr<OPipe> m_pipe;
    LogEntry::LogContext m_context;

    std::string last_str = "";
    
    MO_FUNCTION default_formatter(uint_t alignedColOffset, uint_t maxColWidth, std::function<std::string(const LogEntry::LogContext&)> prefix) MO_NOEXCEPT
        : m_alignedColOffset(alignedColOffset),
        m_maxColWidth(maxColWidth),
        m_prefix(prefix)
    {
        last_str.reserve(512);
    }

    MO_FUNCTION void init(std::shared_ptr<OPipe> pipe, LogEntry::LogContext&& context)
    {
        MO_ASSERT_NULL(m_pipe, "default_formatter has already been init. Did you forget a called to `finalize()` ?");
        MO_ASSERT_NON_NULL(pipe, "default_formatter require a valid OPipe handle");
        m_pipe = pipe;
        m_context = context;

        std::string prefix = m_prefix(m_context);
        if(prefix.size() < m_alignedColOffset) prefix += std::string(m_alignedColOffset - prefix.size(), ' ');
        m_pipe->write(prefix.data(), prefix.size());
    }

    MO_FUNCTION void log(const std::string& str)
    {
        MO_ASSERT_NON_NULL(m_pipe, "default_formatter detected a call to `log(const std::string&)` prior to its initialisation");
        for(uint_t i = 0; i < str.size(); ++i) {
            if(str[i] == '\n') {
                last_str += "\n" + std::string(m_alignedColOffset, ' ');
                m_pipe->write(last_str.data(), last_str.size());
                last_str.clear();
            }
            else if(last_str.size() < (m_maxColWidth - m_alignedColOffset)) {
                last_str += str[i];
            }
            else {
                last_str += "\n" + std::string(m_alignedColOffset, ' ');
                m_pipe->write(last_str.data(), last_str.size());
                last_str = std::string(1, str[i]);
            }
        }

        // for(uint_t i = 0; i < str.size(); ++i) {
        //     if(str[i] == '\n') {
        //         last_str += '\n' + std::string(m_alignedColOffset, ' ');
        //         m_pipe->write(last_str.data(), last_str.size());
        //         last_str.clear();
        //     }
        //     else if(last_str.size() < (m_maxColWidth - m_alignedColOffset)) {
        //         last_str += str[i];
        //     }
        //     else {
        //         last_str += '\n' + std::string(m_alignedColOffset, ' ');
        //         m_pipe->write(last_str.data(), last_str.size());
        //         last_str.clear();
        //         // last_str += str[i];
        //     }
        // }
    }

    MO_FUNCTION void log(PipeFlag flag)
    {
        MO_ASSERT_NON_NULL(m_pipe, "default_formatter detected a call to `log(PipeFlag)` prior to its initialisation");
        m_pipe->write(flag); 
    }

    MO_FUNCTION void finalize()
    {
        MO_ASSERT_NON_NULL(m_pipe, "default_formatter detected a call to `finalize` prior to its initialisation");
        
        if(!last_str.empty()) m_pipe->write(last_str.data(), last_str.size());
        m_pipe->write(Endl);
        m_pipe = nullptr;
    }
};

MO_FUNCTION std::unique_ptr<Logger::formatter_t> Molog::createDefaultFormatter(uint_t alignedColOffset, uint_t maxColWidth, std::function<std::string(const LogEntry::LogContext&)> prefix)
{
    MO_ASSERT(alignedColOffset < maxColWidth, "Molog::createDefaultFormatter require the column width to be strictly positive therefore alignedColOffset must be strictly smaller than maxColWidth");
    MO_ASSERT_NON_NULL(prefix, "Molog::createDefaultFormatter require the prefix callback to be valid");

    return std::make_unique<default_formatter>(alignedColOffset, maxColWidth, prefix);
}


namespace Molog {
    MO_EXPORT Logger stdlogger(std::shared_ptr<OPipe>(&stdpipe, [](auto*) {}), 
        createDefaultFormatter(50, 120, [](const LogEntry::LogContext &context){
            time_t time = std::time(0);
            struct std::tm* tm_ = std::localtime(&time);

            char buffer[256];
            size_t buffersize = std::strftime(buffer, 256, "[%Y-%m-%d %H:%M:%S UTC%z]", tm_);

            std::string severity_str = "";
            if(context.severity == Severity::Verbose) severity_str = "Verbose";
            else if(context.severity == Severity::Status) severity_str = "Status";
            else if(context.severity == Severity::Note) severity_str = "Note";
            else if(context.severity == Severity::Warning) severity_str = "Warning";
            else if(context.severity == Severity::Error) severity_str = "Error";
                
            return std::string(buffer, buffersize) + " - (" + severity_str + ") : ";
        }));
    
}
