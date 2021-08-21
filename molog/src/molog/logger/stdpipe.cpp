/**
 * @file stdpipe.cpp
 * @author Guillaume Boyé
 * @version 0.1
 * @date 2021-08-21
 * 
 * @copyright MIT License
 * Copyright (c) 2021 Guillaume Boyé
 */
#include "opipe.hpp"
#include <iostream>
#include <molog/assertion.hpp>

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

    }

    MO_FUNCTION const char* name() const MO_NOEXCEPT override
    {
        return m_name.c_str();
    }

    MO_FUNCTION flag_t flag() const MO_NOEXCEPT override
    {
        return (m_isOpenned() ? OPipe::Open : 0x0) |
               (m_changeOpenState ? OPipe::Closable : 0x0) |
               OPipe::Colorized;
    }
};

MO_FUNCTION std::unique_ptr<OPipeImpl> Molog::streamToPipeImpl(std::ostream& _ostream, std::function<bool()> isOpenned, const char* name, std::function<void(bool)> changeOpenState)
{
    return std::make_unique<StdPipeImpl>(_ostream, isOpenned, changeOpenState, name);
}

namespace Molog
{
    MO_EXPORT OPipe& stdpipe = OPipe(streamToPipeImpl(std::cout, [](){ return true; }, "stdpipe", nullptr));
}
