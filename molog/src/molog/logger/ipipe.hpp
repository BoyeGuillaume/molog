/**
 * @file ipipe.hpp
 * @author Guillaume Boyé
 * @version 0.1.2
 * @date 2021-08-22
 * 
 * @copyright MIT License
 * Copyright (c) 2021 Guillaume Boyé
 */

#pragma once

#include <string>
#include <istream>
#include <functional>

#include <molog/logger/opipe.hpp>
#include <molog/mologexcept.hpp>



namespace Molog {

    /**
     * @brief defines the implementation of a Molog::IPipe object
     */
    struct IPipeImpl {
        /**
         * @brief open the pipe. Notice that in case of error this should just return (and let the state to close)
         * the error will be handled by the Molog::IPipe::open()
         */
        virtual void open() MO_NOEXCEPT = 0;

        /**
         * @brief close the pipe. Notice that in case of error this should just return (and let the state to open)
         * the error will be handled by the Molog::IPipe::close()
         */
        virtual void close() MO_NOEXCEPT = 0;

        /**
         * @brief read raw data from the pipe (could be binary data). In case of any errors
         * throw the error directly
         * 
         * @param data a C-Style pointer to the data
         * @param size the size of the pointer that can be written to
         * @return uint_t the size of the actual result read from the pipe
         */
        virtual uint_t read(char* data, uint_t size) = 0;

        /**
         * @brief retrieve the name of the implementation
         * 
         * @return const char* A C-Style string holding the name of the implementation
         */
        virtual const char* name() const MO_NOEXCEPT = 0;

        /**
         * @brief retrieve the flag caracterising the state of the pipe
         * 
         * @return flag_t see IPipe::Flag
         */
        virtual flag_t flag() const MO_NOEXCEPT = 0;

        /**
         * @brief destroy the IPipeImpl object
         */
        virtual ~IPipeImpl() = default;
    };

    /**
     * @brief defines a basic pipe that can be read from. Each pipe are link
     * with a Molog::IPipeImpl.
     * 
     * @note the implementation may change throughout the execution and isn't guarented to stay imuable
     * 
     * Notice that if an IPipe is given no implementation it's default behavior will be to be marked as EOF
     */
    class MO_CLASS IPipe final {
        MO_DISABLE_COPY_MOVE(IPipe);
    public:
        /// @copydoc OPipe::Flag
        using Flag = OPipe::Flag;

        /**
         * @brief Constructor with implementation
         * 
         * @param impl the implementation used by this IPipe
         */
        MO_FUNCTION IPipe(std::unique_ptr<IPipeImpl> impl) MO_NOEXCEPT;

        /**
         * @brief Constructor with no implementation
         */
        MO_FUNCTION IPipe(std::nullptr_t) MO_NOEXCEPT;

        /**
         * @brief Default destructor
         */
        MO_FUNCTION ~IPipe();

        /**
         * @brief Set the implementation of the IPipe
         * 
         * @param impl the implementation used by the IPipe
         */
        MO_FUNCTION void setImplementation(std::unique_ptr<IPipeImpl> impl);

        /**
         * @brief open the pipe object
         * 
         * @throw Molog::Exception if the pipe could not be opened and
         * if throwOnError is sets. Overwise a simple call to
         * Molog::OPipe::isOpen() can determine the result of the operation
         */
        MO_FUNCTION void open();

        /**
         * @brief close the pipe object.
         * 
         * @throw Molog::Exception if the pipe could not be closed and
         * if throwOnError is sets. Overwise a simple call to
         * Molog::OPipe::isClose() can determine the result of the operation
         */
        MO_FUNCTION void close();

        /**
         * @brief read raw data from the pipe
         * 
         * @param data a pointer (that must at least be allocated for a size (>= size)) where the
         * resulting data will be stored
         * @param size the size of the maximum amount of data that will be read by the pipe
         * @return uint_t the amount of data actually read by the pipe
         */
        MO_FUNCTION uint_t read(char* data, uint_t size);

        /**
         * @brief Set the ThrowOnError state.
         * 
         * When an error will occure in the method Molog::OPipe::open,
         * Molog::IPipe::close, Molog::IPipe::write it will throw an
         * Molog::Exception.
         * 
         * @note even if this flag is not HIGH an exception may occured in the 
         * implementation if the write operation failed
         * 
         * @param value 
         */
        inline void setThrowOnError(bool value) MO_NOEXCEPT {
            m_doNotThrowExceptionOnFailure = !value;
        }

        /**
         * @brief retrieve the name of the implementation
         * 
         * @return const char* a c-style string that is the name of the implementation
         */
        inline const char* name() const MO_NOEXCEPT {
            return m_impl ? m_impl->name() : "";
        }

        /**
         * @brief check whever or not the pipe is open
         * 
         * @return bool if the pipe is open 
         */
        inline bool isOpen() const MO_NOEXCEPT {
            return m_impl ? (m_impl->flag() & Flag::Open) : true;
        }

        /**
         * @brief check whever or not the pipe is closed
         * 
         * @return bool if the pipe is closed
         */
        inline bool isClosed() const MO_NOEXCEPT {
            return !isOpen();
        }

        /**
         * @brief check whever or not a pipe can be closed
         * 
         * @return bool if the pipe is closable
         */
        inline bool isClosable() const MO_NOEXCEPT {
            return m_impl ? (m_impl->flag() & Flag::Closable) : false;
        }

        /**
         * @brief check whever or not a pipe is in EndOfFile mode
         * 
         * @return bool if this is the case 
         */
        inline bool eof() const MO_NOEXCEPT {
            return m_impl ? (m_impl->flag() & Flag::EndOfFile) : true;
        }

        /**
         * @brief check whever or not a pipe is buffered
         * 
         * notice that if a pipe is buffered then it may not write directly the data
         * but instead append a buffer.
         * the usage of the Molog::PipeFlag::Endl or Molog::PipeFlag::Flush can
         * force flushing the buffer
         * 
         * @return bool return if the pipe is buffered 
         */
        inline bool isBuffered() const MO_NOEXCEPT {
            return m_impl ? (m_impl->flag() & Flag::Buffered) : false;
        }

    private:
        bool                                     m_doNotThrowExceptionOnFailure;
        std::unique_ptr<IPipeImpl>               m_impl;
    };

}
