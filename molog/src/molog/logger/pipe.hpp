/**
 * @file pipe.hpp
 * @author Guillaume Boyé
 * @version 0.1.4
 * @date 2021-08-22
 * 
 * @copyright MIT License
 * Copyright (c) 2021 Guillaume Boyé
 */

#pragma once

#include <string>
#include <memory>
#include <filesystem>

#include <molog/mologexcept.hpp>
#include <molog/logger/ipipe.hpp>
#include <molog/logger/opipe.hpp>



namespace Molog {

    class MO_CLASS Pipe final {
        MO_DISABLE_COPY_MOVE(Pipe);
    public:
        MO_FUNCTION Pipe(std::unique_ptr<IPipeImpl> ipipe, std::unique_ptr<OPipeImpl> opipe);
        MO_FUNCTION ~Pipe();

        inline OPipe& output() MO_NOEXCEPT {
            return m_opipe;
        }

        inline IPipe& input() MO_NOEXCEPT {
            return m_ipipe;
        }

    private:
        OPipe m_opipe;
        IPipe m_ipipe;
    };

    MO_FUNCTION std::shared_ptr<IPipe> fopen_r(const std::filesystem::path& path);
    MO_FUNCTION std::shared_ptr<OPipe> fopen_w(const std::filesystem::path& path, bool append = false);
}
