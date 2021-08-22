/**
 * @file opipe.hpp
 * @author Guillaume Boyé
 * @version 0.1
 * @date 2021-08-21
 * 
 * @copyright MIT License
 * Copyright (c) 2021 Guillaume Boyé
 * 
 */

#pragma once

#include <string>
#include <memory>
#include <ostream>
#include <functional>

#include <molog/mologexcept.hpp>



namespace Molog {

    /**
     * @brief enumerate flag that are not string but can modify the formatting
     * of the pipe
     */
    enum PipeFlag {
        /**
         * @brief Insert a new line in the pipe. In buffered implementation this flush
         * the buffer and write it
         * 
         */
        Endl,

        /**
         * @brief Only play a role in buffered implementation where it flush the 
         * buffer and write it to the screen
         */
        Flush,

        /**
         * @brief Define foregrounds and backgrounds colors for colorized stream
         */
        Reset,
        Bold,
        Dark,
        Italic,
        Underline,
        Blink,
        Reserve,
        Concealed,
        Crossed,

        ColorGrey,
        ColorRed,
        ColorGreen,
        ColorYellow,
        ColorBlue,
        ColorMagenta,
        ColorCyan,
        ColorWhite,
        ColorBrightGrey,
        ColorBrightRed,
        ColorBrightGreen,
        ColorBrightYellow,
        ColorBrightBlue,
        ColorBrightMagenta,
        ColorBrightCyan,
        ColorBrightWhite,
        BackgroundGrey,
        BackgroundRed,
        BackgroundGreen,
        BackgroundYellow,
        BackgroundBlue,
        BackgroundMagenta,
        BackgroundCyan,
        BackgroundWhite,
        BackgroundBrightGrey,
        BackgroundBrightRed,
        BackgroundBrightGreen,
        BackgroundBrightYellow,
        BackgroundBrightBlue,
        BackgroundBrightMagenta,
        BackgroundBrightCyan,
        BackgroundBrightWhite,
    };

    /**
     * @brief defines the implementation of a Molog::OPipe object
     */
    struct OPipeImpl {
        /**
         * @brief open the pipe. Notice that in case of error this should just return (and let the state to close)
         * the error will be handled by the Molog::OPipe::open()
         */
        virtual void open() MO_NOEXCEPT = 0;

        /**
         * @brief close the pipe. Notice that in case of error this should just return (and let the state to open)
         * the error will be handled by the Molog::OPipe::close()
         */
        virtual void close() MO_NOEXCEPT = 0;

        /**
         * @brief write a string to the pipe (could be binary data). In case of error throw the error directly
         * 
         * @param data a C-Style pointer to the data
         * @param size the size of the data to be written to the pipe
         */
        virtual void write(const char* data, uint_t size) = 0;

        /**
         * @brief write a flag to the pipe. In case of error throw the error directly
         * 
         * @param flag the flag to be written to the pipe
         */
        virtual void write(PipeFlag flag) = 0;

        /**
         * @brief retrieve the name of the implementation
         * 
         * @return const char* A C-Style string holding the name of the implementation
         */
        virtual const char* name() const MO_NOEXCEPT = 0;

        /**
         * @brief retrieve the flag caracterising the state of the pipe
         * 
         * @return flag_t see OPipe::Flag
         */
        virtual flag_t flag() const MO_NOEXCEPT = 0;

        /**
         * @brief destroy the OPipeImpl object
         */
        virtual ~OPipeImpl() = default;
    };

    /**
     * @brief defines a basic pipe that can be written to. Each pipe are linked
     * to an Molog::OPipeImpl. Notice that the implementation may change throughout the execution
     * and isn't guarente to stay imuable
     * 
     * Notice that if an OPipe is given no implementation it's default behavior will be to do nothing
     */
    class MO_CLASS OPipe {
        MO_DISABLE_COPY_MOVE(OPipe);
    public:
        /**
         * @brief define the different possible states of the pipe 
         */
        enum Flag : flag_t
        {
            /**
             * @brief whever or not the pipe can handle color
             */
            Colorized  = 1 << 0,

            /**
             * @brief whever or not the pipe is currently open
             */
            Open       = 1 << 1,

            /**
             * @brief whever or not the pipe can be closed 
             */
            Closable   = 1 << 2,

            /**
             * @brief whever or not the pipe is buffered (in which case
             * the writing operation is guarente to be done when receiving Endl)
             */
            Buffered   = 1 << 3
        };

        /**
         * @brief construct the OPipe object
         * 
         * @param impl the implementation used by this object (may be nullptr)
         */
        MO_FUNCTION OPipe(std::unique_ptr<OPipeImpl> impl);

        /**
         * @brief constuct the OPipe without any implementation
         */
        MO_FUNCTION OPipe(std::nullptr_t);

        /**
         * @brief Destroy the OPipe object
         */
        MO_FUNCTION ~OPipe();

        /**
         * @brief Set the implementation of the object
         * 
         * @param impl the new implementation (will override the hold one)
         */
        MO_FUNCTION void setImplementation(std::unique_ptr<OPipeImpl> impl);


        /**
         * @brief open the pipe object.
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
         * @brief write raw data to the pipe
         * 
         * @throw Molog::Exception if the pipe is not open or
         * if an error was thrown by the implementation
         * 
         * @param data a pointer to the data to be written to the pipe
         * @param size the size of the object to be written to the pipe
         */
        MO_FUNCTION void write(const char* data, uint_t size);

        /**
         * @brief write a flag to the pipe
         * 
         * @throw Molog::Exception if the pipe is not open or 
         * if an error was thrown by the implementation
         * 
         * @param flag write a flag to the pipe
         */
        MO_FUNCTION void write(PipeFlag flag);

        /**
         * @brief Set the ThrowOnError state.
         * 
         * When an error will occure in the method Molog::OPipe::open,
         * Molog::OPipe::close, Molog::OPipe::write it will throw an
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

        /**
         * @brief chech whever or not a pipe is colorized
         * 
         * @return bool do the pipe handle colors
         */
        inline bool isColorized() const MO_NOEXCEPT {
            return m_impl ? (m_impl->flag() & Flag::Colorized) : false;
        }

    private:
        bool                                     m_doNotThrowExceptionOnFailure;
        std::unique_ptr<OPipeImpl>               m_impl;
    };

    /**
     * @brief create a OPipeImpl object from the given std::ostream
     * 
     * @param _ostream a reference to the std::ostream& the user has to guarente that the ref. last
     * long enought for safe use
     * @param isOpenned a function (must not be nullptr) that gave insight about whever or not the stream is open
     * @param name the name of the stream
     * @param changeOpenState an optional function (can be nullptr) that enable the implementation to open and close the stream
     * @return std::unique_ptr<OPipeImpl> the newly create pipe implementation
     */
    MO_FUNCTION std::unique_ptr<OPipeImpl> streamToPipeImpl(std::ostream& _ostream, std::function<bool()> isOpenned, const char* name, std::function<void(bool)> changeOpenState = nullptr);
    
    /**
     * @brief Standard pipe output (correspdonging to the stream std::cout)
     */
    extern OPipe stdpipe;

}
