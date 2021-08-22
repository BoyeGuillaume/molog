/**
 * @file ipipe.cpp
 * @author Guillaume Boyé
 * @version 0.1.2
 * @date 2021-08-22
 * 
 * @copyright MIT License
 * Copyright (c) 2021 Guillaume Boyé
 */
#include "ipipe.hpp"
#include <molog/assertion.hpp>

MO_USE_NAMESPACE;


MO_FUNCTION IPipe::IPipe(std::unique_ptr<IPipeImpl> impl) MO_NOEXCEPT
: m_impl(std::move(impl)),
  m_doNotThrowExceptionOnFailure(true)
{

}

MO_FUNCTION IPipe::IPipe(std::nullptr_t)
: m_impl(nullptr),
m_doNotThrowExceptionOnFailure(true)
{

}

MO_FUNCTION IPipe::~IPipe()
{

}

MO_FUNCTION void IPipe::setImplementation(std::unique_ptr<IPipeImpl> impl)
{
    m_impl = std::move(impl);
}

MO_FUNCTION void IPipe::open()
{
    if(m_impl && isClosed())
    {
        m_impl->open();
        MO_FORCE_ASSERT(m_doNotThrowExceptionOnFailure || isOpen(), "failed to open pipe with implementation " + std::string(m_impl->name()));   
    }
}

MO_FUNCTION void IPipe::close()
{
    if(m_impl && isOpen())
    {
        m_impl->close();
        MO_FORCE_ASSERT(m_doNotThrowExceptionOnFailure || isClosed(), "failed to close pipe with implementation " + std::string(m_impl->name()));
    }
}

MO_FUNCTION uint_t IPipe::read(char* data, uint_t size)
{
    if(m_impl)
    {
        MO_ASSERT(isOpen(), "IPipe::read require the channel to be pen prior its usage");
        return m_impl->read(data, size);
    }
    return 0;
}
