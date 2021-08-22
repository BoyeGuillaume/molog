#include "pipe.hpp"
#include <fstream>
#include <molog/assertion.hpp>

MO_USE_NAMESPACE;

MO_CLASS struct fOPipeImpl : public OPipeImpl
{
    std::ofstream m_ofstream;
    std::filesystem::path m_path;
    bool m_append;

    MO_FUNCTION fOPipeImpl(const std::filesystem::path& path, bool append)
        : m_path(path),
        m_append(append)
    {
        open();
    }

    MO_FUNCTION void open() MO_NOEXCEPT override
    {
        if(m_ofstream.is_open()) return;
        try {
            std::ios_base::openmode mode = std::ios::out | std::ios::binary;
            if(m_append) mode |= std::ios::app;
            m_ofstream.open(m_path, mode);
        }
        catch(std::exception&){}
    }

    MO_FUNCTION void close() MO_NOEXCEPT override
    {
        if(!m_ofstream.is_open()) return;
        try {
            m_ofstream.close();
        }
        catch(std::exception&){}
    }

    MO_FUNCTION void write(const char* data, uint_t size) override
    {
        MO_ASSERT(m_ofstream.is_open(), "cannot write the file as it ain't open yet");
        m_ofstream.write(data, size);
    }

    MO_FUNCTION void write(PipeFlag flag) override
    {
        switch(flag)
        {
        case Endl:
            m_ofstream << std::endl;
            break;
        
        case Flush:
            m_ofstream.flush();
            break;

        default:
            break;
        }
    }

    MO_FUNCTION const char* name() const MO_NOEXCEPT override
    {
        return "ofstream";
    }

    MO_FUNCTION flag_t flag() const MO_NOEXCEPT override
    {
        flag_t flag_;
        flag_ |= OPipe::Closable;
        
        if(m_ofstream.is_open()) flag_ |= OPipe::Open;
        if(m_ofstream.eof()) flag_ |= OPipe::EndOfFile;

        return flag_;
    }
};

MO_CLASS struct fIPipeImpl : public IPipeImpl
{
    std::ifstream m_ifstream;
    std::filesystem::path m_path;

    MO_FUNCTION fIPipeImpl(const std::filesystem::path& path)
        : m_path(path)
    {
        open();
    }

    MO_FUNCTION void open() MO_NOEXCEPT override
    {
        if(m_ifstream.is_open()) return;
        try {
            std::ios_base::openmode mode = std::ios::in | std::ios::binary;
            m_ifstream.open(m_path, mode);
        }
        catch(std::exception&){}
    }

    MO_FUNCTION void close() MO_NOEXCEPT override
    {
        if(!m_ifstream.is_open()) return;
        try {
            m_ifstream.close();
        }
        catch(std::exception&){}
    }

    MO_FUNCTION uint_t read(char* data, uint_t size) override
    {
        MO_ASSERT(m_ifstream.is_open(), "cannot read the file as it ain't open yet");
        
        try {
            auto p = m_ifstream.gcount(); // do not use tellg()
            m_ifstream.read(data, size);
            auto k = m_ifstream.gcount();
            return (uint_t) (k - p);
        }
        catch(const std::exception& e) {
            throw new Molog::Exception("cannot read file " + m_path.string() + " : " + std::string(e.what()));
        }
    }

    MO_FUNCTION const char* name() const MO_NOEXCEPT override
    {
        return "ifstream";
    }

    MO_FUNCTION flag_t flag() const MO_NOEXCEPT override
    {
        flag_t flag_;
        flag_ |= OPipe::Closable;
        
        if(m_ifstream.is_open()) flag_ |= OPipe::Open;
        if(m_ifstream.eof()) flag_ |= OPipe::EndOfFile;

        return flag_;
    }
};

MO_FUNCTION Pipe::Pipe(std::unique_ptr<IPipeImpl> ipipe, std::unique_ptr<OPipeImpl> opipe)
    : m_opipe(std::move(opipe)),
    m_ipipe(std::move(ipipe))
{

}

MO_FUNCTION Pipe::~Pipe()
{

}

MO_FUNCTION std::shared_ptr<IPipe> Molog::fopen_r(const std::filesystem::path& path)
{
    return std::make_shared<IPipe>(std::make_unique<fIPipeImpl>(path));
}

MO_FUNCTION std::shared_ptr<OPipe> Molog::fopen_w(const std::filesystem::path& path, bool append)
{
    return std::make_shared<OPipe>(std::make_unique<fOPipeImpl>(path, append));
}

