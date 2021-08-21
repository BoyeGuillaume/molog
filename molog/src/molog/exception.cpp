#include "exception.hpp"

MO_USE_NAMESPACE;

MO_FUNCTION Exception::Exception(const std::string& str)
: m_what(str)
{
    
}

MO_FUNCTION const char* Exception::what() const noexcept
{
    return m_what.c_str();
}

