/**
 * @file endianness.hpp
 * @author Guillaume Boyé
 * @version 0.1.4
 * @date 2021-08-22
 * 
 * @copyright MIT License
 * Copyright (c) 2021 Guillaume Boyé
 */
#pragma once

#include <type_traits>

#include <molog/mologexcept.hpp>



namespace Molog
{
    /**
     * @brief enumerate all supported endianness type
     * @link https://en.wikipedia.org/wiki/Endianness @endlink
     */
    enum class Endianness : uint8_t
    {
        /**
         * @brief Big Endian
         */
        Big,

        /**
         * @brief Little Endian 
         */
        Little
    };

    /**
     * @brief Utility class that enable to transit from one endianness to another 
     */
    class Endian {
    private:
        static constexpr uint32_t uint32_ = 0x01020304;
        static constexpr uint8_t magic_ = (const uint8_t&) uint32_;
    
    public:
        /**
         * @brief field defining the preferredEndianness (used for compatibility in order to create generic portable endianess) 
         */
        static constexpr Endianness preferredEndianness = Endianness::Little;

        /**
         * @brief whever or not we are currently working with little endian
         */
        static constexpr bool little = (magic_ == 0x04);

        /**
         * @brief whever or not we are currently working with big endian
         */
        static constexpr bool big = (magic_ == 0x01);

        /**
         * @brief the current endianness (using the Endianess enum) 
         */
        static constexpr Endianness endianness = (little) ? (Endianness::Little) : (Endianness::Big);
        static_assert(little | big, "Molog only support platform with BigEndian or LittleEndian");

        /**
         * @brief Swap the endianness of the parameter T 
         * 
         * @tparam T the type of the parameter
         * @param u the value to be swapped
         * @return T the same value but in the inverse endianness
         */
        template<typename T>
        static inline T swapEndian(T u)
        {
            static_assert(CHAR_BIT == 8, "Molog only support platform with BYTE of size 8 bits");

            union {
                T u;
                unsigned char u8[sizeof(T)];
            } source, dest;
            source.u = u;

            for (uint_t i = 0; i < sizeof(T); ++i) {
                dest.u8[k] = source.u8[sizeof(T) - k - 1];
            }

            return dest.u;
        }

        /**
         * @brief convert the parameter T to the preferred endianness (for portable database)
         * 
         * @tparam T the type of the parameters to be converted
         * @param u the parameter to be converted
         * @return T the same value but in the preferred endiannes
         */
        template<typename T>
        static inline T convertToPreferredEndianness(T u);

    private:
        Endian() = delete;
    };


#ifdef __MO_TARGET_MSC
    template<>
    inline uint64_t Endian::swapEndian(uint64_t u)
    {
        return _byteswap_uint64(u);
    }

    template<>
    inline uint32_t Endian::swapEndian(uint32_t u)
    {
        return _byteswap_ulong(u);
    }

    template<>
    inline uint16_t Endian::swapEndian(uint16_t u)
    {
        return _byteswap_ushort(u);
    }
#else
    template<>
    inline uint64_t Endian::swapEndian(uint64_t u)
    {
        return __builtin_bswap64(u);
    }

    template<>
    inline uint32_t Endian::swapEndian(uint32_t u)
    {
        return __builtin_bswap32(u);
    }
#endif

    template<>
    inline int16_t Endian::swapEndian(int16_t u) { return (int16_t)Endian::swapEndian<uint16_t>((uint16_t)u); }

    template<>
    inline int32_t Endian::swapEndian(int32_t u) { return (int32_t)Endian::swapEndian<uint32_t>((uint32_t)u); }

    template<>
    inline int64_t Endian::swapEndian(int64_t u) { return (int64_t)Endian::swapEndian<uint64_t>((uint64_t)u); }

    template<>
    inline uint8_t Endian::swapEndian(uint8_t u) { return u; }

    template<>
    inline int8_t Endian::swapEndian(int8_t u) { return u; }

    template<typename T>
    inline T Endian::convertToPreferredEndianness(T u)
    {
        if constexpr (Endian::endianness == Endian::preferredEndianness)
        {
            return u;
        }
        else
        {
            return swapEndian<T>(u);
        }
    }

}
