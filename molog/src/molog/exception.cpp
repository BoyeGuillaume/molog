/**
 * @file exception.cpp
 * @author Guillaume Boyé
 * @version 0.1.4
 * @date 2021-08-21
 * 
 * @copyright MIT License
 * Copyright (c) 2021 Guillaume Boyé
 * 
 */

#include "exception.hpp"

MO_USE_NAMESPACE;

MO_FUNCTION Exception::Exception(std::string what)
: m_what(std::move(what))
{

}

MO_FUNCTION const char* Exception::what() const MO_NOEXCEPT
{
    return m_what.c_str();
}

