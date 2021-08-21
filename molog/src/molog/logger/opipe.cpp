/**
 * @file opipe.cpp
 * @author Guillaume Boyé
 * @version 0.1
 * @date 2021-08-21
 * 
 * @copyright MIT License
 * Copyright (c) 2021 Guillaume Boyé
 * 
 */

#include "opipe.hpp"
#include <molog/assertion.hpp>

MO_USE_NAMESPACE;

MO_FUNCTION OPipe::OPipe(std::unique_ptr<OPipeImpl> impl)
: m_impl(std::move(impl)), m_doNotThrowExceptionOnFailure(true)
{

}

MO_FUNCTION OPipe::OPipe(std::nullptr_t)
: m_impl(nullptr), m_doNotThrowExceptionOnFailure(true)
{

}

MO_FUNCTION OPipe::~OPipe()
{

}

MO_FUNCTION void OPipe::setImplementation(std::unique_ptr<OPipeImpl> impl)
{
    m_impl = std::move(impl);
}

MO_FUNCTION void OPipe::open()
{
    if(m_impl && isClosed())
    {
        m_impl->open();
        MO_FORCE_ASSERT(m_doNotThrowExceptionOnFailure || isOpen(), "failed to open pipe with implementation " + std::string(m_impl->name()));   
    }
}

MO_FUNCTION void OPipe::close()
{
    if(m_impl && isOpen())
    {
        m_impl->close();
        MO_FORCE_ASSERT(m_doNotThrowExceptionOnFailure || isClosed(), "failed to close pipe with implementation " + std::string(m_impl->name()));
    }
}

MO_FUNCTION void OPipe::write(const char* data, uint_t size)
{
    if(m_impl)
    {
        MO_ASSERT(isOpen(), "OPipe::write require the channel to be open prior its usage");
        m_impl->write(data, size);
    }
}

MO_FUNCTION void OPipe::write(PipeFlag flag)
{
    if(m_impl)
    {
        MO_ASSERT(isOpen(), "OPipe::write require the channel to be open prior its usage");
        m_impl->write(flag);
    }
}


