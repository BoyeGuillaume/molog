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
