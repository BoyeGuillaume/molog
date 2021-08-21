#pragma once

#include <exception>
#include <string>

#include <molog/mologexcept.hpp>



namespace Molog {

    class MO_CLASS Exception : public std::exception {
    public:
        MO_FUNCTION Exception(const std::string& str = "");

        virtual MO_FUNCTION const char* what() const override;

    private:
        std::string m_what;
    };

}
