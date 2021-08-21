#include "exception.hpp"

MO_USE_NAMESPACE;

MO_FUNCTION Exception::Exception(std::string what)
: m_what(std::move(what))
{
    
}

MO_FUNCTION const char* Exception::what() const noexcept
{
    return m_what.c_str();
}

