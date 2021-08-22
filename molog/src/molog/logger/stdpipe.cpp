/**
 * @file stdpipe.cpp
 * @author Guillaume Boyé
 * @version 0.1.4
 * @date 2021-08-21
 * 
 * @copyright MIT License
 * Copyright (c) 2021 Guillaume Boyé
 */
#include "opipe.hpp"
#include <iostream>
#include <molog/assertion.hpp>

#ifdef MO_PLATFORM_WINDOW
 #include <windows.h>
 #include <io.h>
 
 #define WIN_OR_POSIX_CHANGE_ATTR(seq, for, back) if(is_colorized(m_ostream)) win_change_attribute(m_ostream, for, back)
 #define POSIX(seq) 
#else 
 #include <unistd.h>

 #define WIN_OR_POSIX_CHANGE_ATTR(seq, for, back) if(is_colorized(m_ostream)) m_ostream << seq
 #define POSIX(seq) if(is_colorized(m_ostream)) m_ostream << seq
#endif


inline bool is_atty (const std::ostream& stream)
{
    FILE* std_stream = nullptr;
    if(&stream == &std::cout) std_stream = stdout;
    else if(&stream == &std::cerr) std_stream = stderr;

    if(!std_stream) return false;

#ifdef MO_PLATFORM_WINDOW
    return _isatty(_fileno(std_stream));
#else
    return isatty(fileno(std_stream));
#endif
}

inline bool is_colorized(std::ostream& stream)
{
    return is_atty(stream);
}

#ifdef MO_PLATFORM_WINDOW
inline void win_change_attribute(std::ostream &stream, int foreground, int background)
{
    static WORD defaultAttributes = 0;
    if (!is_atty(stream))
        return;

    // get terminal handle
    HANDLE hTerminal = INVALID_HANDLE_VALUE;
    if (&stream == &std::cout)
        hTerminal = GetStdHandle(STD_OUTPUT_HANDLE);
    else if (&stream == &std::cerr)
        hTerminal = GetStdHandle(STD_ERROR_HANDLE);

    if (!defaultAttributes)
    {
        CONSOLE_SCREEN_BUFFER_INFO info;
        if (!GetConsoleScreenBufferInfo(hTerminal, &info))
            return;
        defaultAttributes = info.wAttributes;
    }

    // restore all default settings
    if (foreground == -1 && background == -1)
    {
        SetConsoleTextAttribute(hTerminal, defaultAttributes);
        return;
    }

    // get current settings
    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(hTerminal, &info))
        return;

    if (foreground != -1)
    {
        info.wAttributes &= ~(info.wAttributes & 0x0F);
        info.wAttributes |= static_cast<WORD>(foreground);
    }

    if (background != -1)
    {
        info.wAttributes &= ~(info.wAttributes & 0xF0);
        info.wAttributes |= static_cast<WORD>(background);
    }

    SetConsoleTextAttribute(hTerminal, info.wAttributes);
}
#endif

MO_USE_NAMESPACE;

struct MO_CLASS StdPipeImpl : OPipeImpl
{
    std::ostream& m_ostream;
    std::function<bool()> m_isOpenned;
    std::function<void(bool)> m_changeOpenState;
    std::string m_name;
    
    MO_FUNCTION StdPipeImpl(std::ostream& _ostream, std::function<bool()> isOpenned, std::function<void(bool)> changeOpenState,  const char* name)
    : m_ostream(_ostream),
    m_isOpenned(isOpenned),
    m_changeOpenState(changeOpenState),
    m_name(name)
    {
        MO_ASSERT(m_isOpenned, "isOpenned function must not be let undefined");
    }

    MO_FUNCTION ~StdPipeImpl()
    {
        if(m_changeOpenState && m_isOpenned())
        {
            m_changeOpenState(false);
        }
    }

    MO_FUNCTION void open() MO_NOEXCEPT override
    {
        if(!m_isOpenned && m_changeOpenState)
        {
            m_changeOpenState(true);
        }
    }
    
    MO_FUNCTION void close() MO_NOEXCEPT override
    {
        if(m_changeOpenState && m_isOpenned())
        {
            m_changeOpenState(false);
        }
    }

    MO_FUNCTION void write(const char* data, uint_t size) override
    {
        m_ostream.write(data, size);
    }

    MO_FUNCTION void write(PipeFlag flag) override
    {
        switch (flag)
        {
        case Endl:
            m_ostream << std::endl;
            break;
        
        case Flush:
            m_ostream.flush();
            break;

        case Reset:
            WIN_OR_POSIX_CHANGE_ATTR("\033[00m", -1, -1);
            break;

        case Bold:
            POSIX("\033[1m");
            break;

        case Dark:
            POSIX("\033[2m");
            break;

        case Italic:
            POSIX("\033[3m");
            break;

        case Underline:
            POSIX("\033[4m");
            break;

        case Blink:
            POSIX("\033[5m");
            break;

        case Reserve:
            POSIX("\033[7m");
            break;

        case Concealed:
            POSIX("\033[8m");
            break;

        case Crossed:
            POSIX("\033[9m");
            break;
            
        case ColorGrey:
            WIN_OR_POSIX_CHANGE_ATTR("\033[30m", 0, -1);
            break;

        case ColorRed:
            WIN_OR_POSIX_CHANGE_ATTR("\033[31m", FOREGROUND_RED, -1);
            break;

        case ColorGreen:
            WIN_OR_POSIX_CHANGE_ATTR("\033[32m", FOREGROUND_GREEN, -1);
            break;

        case ColorYellow:
            WIN_OR_POSIX_CHANGE_ATTR("\033[33m", FOREGROUND_GREEN | FOREGROUND_RED, -1);
            break;

        case ColorBlue:
            WIN_OR_POSIX_CHANGE_ATTR("\033[34m", FOREGROUND_BLUE, -1);
            break;

        case ColorMagenta:
            WIN_OR_POSIX_CHANGE_ATTR("\033[35m", FOREGROUND_BLUE | FOREGROUND_RED, -1);
            break;

        case ColorCyan:
            WIN_OR_POSIX_CHANGE_ATTR("\033[36m", FOREGROUND_BLUE | FOREGROUND_GREEN, -1);
            break;

        case ColorWhite:
            WIN_OR_POSIX_CHANGE_ATTR("\033[37m", FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, -1);
            break;

        case ColorBrightGrey:
            WIN_OR_POSIX_CHANGE_ATTR("\033[90m", 0 | FOREGROUND_INTENSITY, -1);
            break;

        case ColorBrightRed:
            WIN_OR_POSIX_CHANGE_ATTR("\033[91m", FOREGROUND_RED | FOREGROUND_INTENSITY, -1);
            break;

        case ColorBrightGreen:
            WIN_OR_POSIX_CHANGE_ATTR("\033[92m", FOREGROUND_GREEN | FOREGROUND_INTENSITY, -1);
            break;

        case ColorBrightYellow:
            WIN_OR_POSIX_CHANGE_ATTR("\033[93m", FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY, -1);
            break;

        case ColorBrightBlue:
            WIN_OR_POSIX_CHANGE_ATTR("\033[94m", FOREGROUND_BLUE | FOREGROUND_INTENSITY, -1);
            break;

        case ColorBrightMagenta:
            WIN_OR_POSIX_CHANGE_ATTR("\033[95m", FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY, -1);
            break;

        case ColorBrightCyan:
            WIN_OR_POSIX_CHANGE_ATTR("\033[96m", FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY, -1);
            break;

        case ColorBrightWhite:
            WIN_OR_POSIX_CHANGE_ATTR("\033[97m", FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY, -1);
            break;

        case BackgroundGrey:
            WIN_OR_POSIX_CHANGE_ATTR("\033[40m", -1, 0);
            break;

        case BackgroundRed:
            WIN_OR_POSIX_CHANGE_ATTR("\033[41m", -1, BACKGROUND_RED);
            break;

        case BackgroundGreen:
            WIN_OR_POSIX_CHANGE_ATTR("\033[42m", -1, BACKGROUND_GREEN);
            break;

        case BackgroundYellow:
            WIN_OR_POSIX_CHANGE_ATTR("\033[43m", -1, BACKGROUND_GREEN | BACKGROUND_RED);
            break;

        case BackgroundBlue:
            WIN_OR_POSIX_CHANGE_ATTR("\033[44m", -1, BACKGROUND_BLUE);
            break;

        case BackgroundMagenta:
            WIN_OR_POSIX_CHANGE_ATTR("\033[45m", -1, BACKGROUND_BLUE | BACKGROUND_RED);
            break;

        case BackgroundCyan:
            WIN_OR_POSIX_CHANGE_ATTR("\033[46m", -1, BACKGROUND_BLUE | BACKGROUND_GREEN);
            break;

        case BackgroundWhite:
            WIN_OR_POSIX_CHANGE_ATTR("\033[47m", -1, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
            break;

        case BackgroundBrightGrey:
            WIN_OR_POSIX_CHANGE_ATTR("\033[100m", -1, 0 | BACKGROUND_INTENSITY);
            break;

        case BackgroundBrightRed:
            WIN_OR_POSIX_CHANGE_ATTR("\033[101m", -1, BACKGROUND_RED | BACKGROUND_INTENSITY);
            break;

        case BackgroundBrightGreen:
            WIN_OR_POSIX_CHANGE_ATTR("\033[102m", -1, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
            break;

        case BackgroundBrightYellow:
            WIN_OR_POSIX_CHANGE_ATTR("\033[103m", -1, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
            break;

        case BackgroundBrightBlue:
            WIN_OR_POSIX_CHANGE_ATTR("\033[104m", -1, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
            break;

        case BackgroundBrightMagenta:
            WIN_OR_POSIX_CHANGE_ATTR("\033[105m", -1, BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY);
            break;

        case BackgroundBrightCyan:
            WIN_OR_POSIX_CHANGE_ATTR("\033[106m", -1, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
            break;

        case BackgroundBrightWhite:
            WIN_OR_POSIX_CHANGE_ATTR("\033[107m", -1, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
            break;

        }   
    }

    MO_FUNCTION const char* name() const MO_NOEXCEPT override
    {
        return m_name.c_str();
    }

    MO_FUNCTION flag_t flag() const MO_NOEXCEPT override
    {
        return (m_isOpenned() ? OPipe::Open : 0x0) |
               (m_changeOpenState ? OPipe::Closable : 0x0) |
               (is_colorized(m_ostream) ? OPipe::Colorized : 0x0);
    }
};

MO_FUNCTION std::unique_ptr<OPipeImpl> Molog::streamToPipeImpl(std::ostream& _ostream, std::function<bool()> isOpenned, const char* name, std::function<void(bool)> changeOpenState)
{
    return std::make_unique<StdPipeImpl>(_ostream, isOpenned, changeOpenState, name);
}

namespace Molog
{
    MO_EXPORT OPipe stdpipe (streamToPipeImpl(std::cout, [](){ return true; }, "stdpipe", nullptr));
}
