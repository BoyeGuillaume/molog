/**
 * @file logger.hpp
 * @author Guillaume Boyé
 * @version 0.1.2
 * @date 2021-08-21
 * 
 * @copyright MIT License
 * Copyright (c) 2021 Guillaume Boyé
 * 
 */

#pragma once

#include <string>
#include <functional>
#include <memory>
#include <sstream>
#include <list>
#include <variant>
#include <mutex>

#include <molog/mologexcept.hpp>
#include <molog/logger/opipe.hpp>



namespace Molog {
    
    class Logger;

    /**
     * @brief enumerate severity level for the logger
     */
    enum class Severity {
        /**
         * @brief severity verbose defines all information that are just there to be informative and doesn't represent any threats 
         */
        Verbose,

        /**
         * @brief status may be state or point in the program execution 
         */
        Status,

        /**
         * @brief display a note 
         */
        Note,

        /**
         * @brief defines a potential issue or security fault
         */
        Warning,

        /**
         * @brief defines an error 
         */
        Error
    };

    /**
     * @brief enumerate a list of flags that can be used for logging information 
     */
    enum LogFlag : flag_t {
        /**
         * @brief prevent the logger to format the stream notice 
         * that this is the only flag that apply to the whole entry
         * therefore even if it is applied at the end it will disable
         * the entire formatting 
         */
        NoFormatting
    };

    /**
     * @brief defines operator<< for multiple value in order to ease the process of integration using Molog::Logger
     * use Molog::Logger::log(Severity) to create such instance
     * 
     * @code {.cpp}
     * // use Logger stdlogger
     * stdlogger.log(Severity::Note) << NoFormatting << "================ Starting the database ==============" << Endl;
     * stdlogger.log(Severity::Status) << "Running...[OK]";
     * @endcode
     * 
     * @note Molog::LogEntry first save all the flags/text to an list of variant type and the passed this list to the manager
     * Molog::Logger during it's destruction therefore an object is written during it's destruction
     */
    class MO_CLASS LogEntry final {
        friend class Logger;

    public:
        /**
         * @brief context for a log entry 
         */
        struct LogContext {
            /**
             * @brief the severity of the log 
             */
            Severity severity;
        };

        /**
         * @brief Destruction of the LogEntry object. Notice that the writing operation happens during this last steps
         */
        MO_FUNCTION ~LogEntry();

        /**
         * @brief use a modifier Molog::LogFlag
         * 
         * @param flag a LogFlag that modify the behavior of the logger
         * @return LogEntry& self-reference
         */
        MO_FUNCTION LogEntry& operator<<(LogFlag flag);

        /**
         * @brief modify the behavior of the OPipe used by the logger
         * 
         * @param flag a PipeFlag fed into the OPipe of the logger
         * @return LogEntry& self-reference 
         */
        MO_FUNCTION LogEntry& operator<<(PipeFlag flag);

        /**
         * @brief write a string to the logger
         * 
         * @param str the string to be written
         * @return LogEntry& self-reference 
         */
        MO_FUNCTION LogEntry& operator<<(const std::string& str);

    private:
        /**
         * @brief private constructor of the LogEntry
         * 
         * @param logger a pointer to the manager Malog::Logger
         * @param context the logging context associated with this entry
         */
        MO_FUNCTION LogEntry(Logger* logger, LogContext&& context) MO_NOEXCEPT;

        /**
         * @brief the type of each entry in the LogEntry::m_entries field. 
         */
        typedef std::variant<std::string,PipeFlag> entry_t;

        Logger* m_logger;
        LogContext m_context;
        bool m_formatting;
        std::list<entry_t> m_entries;
    };

    /**
     * @brief class that defines a logger that logs entries to and predefined OPipe
     * 
     * Usage:
     * @code {.cpp}
     * Logger logger (std::make_shared<OPipe>(...), std::make_unique<custom_formatter_t>(formatter));
     * logger.log() << "Test string";
     * logger.log() << NoFormatting
     *              << "Hello, world!"
     *              << Endl;
     * @endcode
     * 
     */
    class MO_CLASS Logger final {
        MO_DISABLE_COPY_MOVE(Logger);
        friend class LogEntry;
    
    public:
        /**
         * @brief defines a formatter object that is able to format the logging stream 
         */
        struct formatter_t {
            /**
             * @brief Destroy the formatter object
             */
            virtual ~formatter_t() = default;

            /**
             * @brief initialize the formatter (called everytimes we need to format a new entry)
             * 
             * @param pipe the output pipe. indeed the formatter is the object responsible of writing to the pipe
             * @param context a moved-ref of logging context
             */
            virtual void init(std::shared_ptr<OPipe> pipe, LogEntry::LogContext&& context) = 0;
            
            /**
             * @brief log a string to the OPipe using the formatter. It is granted that this method will only be called after
             * a formatter_t::init(...) and not after a formatter_t::finalize()
             * 
             * @param str the string to be logged using this formatter
             */
            virtual void log(const std::string& str) = 0;

            /**
             * @brief log a PipeFlag modifier to the OPipe. It is granted that this method will only be called after
             * a formatter_t::init(...) and not after a formatter_t::finalize()
             * 
             * @param flag the flag use as a modifier for the OPipe
             */
            virtual void log(PipeFlag flag) = 0;

            /**
             * @brief called to finalize the writing operation. It is granted that this is called after a formatter_t::init()
             */
            virtual void finalize() = 0;
        };

        /**
         * @brief Logger constructor
         * 
         * @param pipe a shared handle to the pipe to be used for the writing operations
         * @param formatter the formatter to be used
         * 
         * @throw Molog::Exception if an configuration error occured. this could be due to the pipe or the formatter beeing nullptr
         */
        MO_FUNCTION Logger(std::shared_ptr<OPipe> pipe, std::unique_ptr<formatter_t> formatter);

        /**
         * @brief destructor of the Logger object
         */
        MO_FUNCTION ~Logger() MO_NOEXCEPT;

        /**
         * @brief create a new LogEntry of a given severity
         * 
         * @param severity the severity of the entry (see Molog::Severity)
         * @return LogEntry the entry created and ready to be used
         */
        MO_FUNCTION LogEntry log(Severity severity);
    
    private:
        /**
         * @brief private method used in LogEntry to perform the writing operation from the entries buffered list
         * 
         * @param entries a ordered list of the entries
         * @param context the logging context
         * @param _formatting whever or not the function should be formatted
         */
        MO_FUNCTION void _log(std::list<LogEntry::entry_t>&& entries, LogEntry::LogContext&& context, bool _formatting);

        std::shared_ptr<OPipe> m_pipe;
        std::unique_ptr<formatter_t> m_formatter;
        std::mutex m_lock;
    };

    /**
     * @brief Create a unique_ptr to the default implementation of the Logger::formatter_t 
     * 
     * @param alignedColOffset the offset between the far-left of the line and the start of the text
     * @param maxColWidth the maximum with of a line (over that will split the line)
     * @param prefix a function that gave the prefix for each entries
     * @return std::unique_ptr<Logger::formatter_t> a unique pointer to an implementation of a Logger::formatter_t hereby created 
     */
    MO_FUNCTION std::unique_ptr<Logger::formatter_t> createDefaultFormatter(uint_t alignedColOffset, uint_t maxColWidth, std::function<std::string(const LogEntry::LogContext&)> prefix);
    
    /**
     * @brief default stdlogger that use stdpipe and a default formatter
     */
    extern Logger stdlogger;
    
}

