/**
 * @file exception.hpp
 * @author Guillaume Boyé
 * @brief 
 * @version 0.1
 * @date 2021-08-21
 * 
 * @copyright MIT License
 * 
 * Copyright (c) 2021 Guillaume Boyé
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the 
 * ), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED 
 * , WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */

#pragma once

#include <exception>
#include <string>

#include <molog/mologexcept.hpp>

/*! \cond PRIVATE */
#define __HELPER_MO_EXPAND_STR(str)                                                                + ((std::string) str)
/*! \endcond */

/**
 * @brief throw an Molog::Exception using the parameters in the macro as error message. Notice that this macro require at least one parameter
 */
#define MO_THROW_EXCEPTION(msg, ...)                                                               throw Molog::Exception(msg MO_FOR_EACH_P0(__HELPER_MO_EXPAND_STR, "", ##__VA_ARGS__))


namespace Molog {

    /**
     * @brief Molog::Exception is the base exception of all exception thrown by the molog library.
     * 
     */
    class MO_CLASS Exception : public std::exception {
    public:
        /**
         * @brief Exception construction require to pass a string as input
         * 
         * @param what a message giving more information about the exception and the context in which it occurred
         */
        MO_FUNCTION Exception(std::string what = "");

        /**
         * @brief overriden method that return an C-style string containing the error message. The modern equivalent (throught the use of std::string) would be 
         * throught the use of Exception::message()
         * 
         * @return const char* the C-Style error message 
         */
        virtual MO_FUNCTION const char* what() const noexcept override;

        /**
         * @brief method that return a string containing the error message. Modern equivalent of Exception::what()
         * 
         * @return const std::string& a const-ref to the error message string
         */
        inline const std::string& message() const noexcept {
            return m_what;
        }

    private:
        std::string m_what;
    };

}
