/**
 * @file serializer.hpp
 * @author Guillaume Boyé
 * @version 0.1.4
 * @date 2021-08-22
 * 
 * @copyright MIT License
 * Copyright (c) 2021 Guillaume Boyé
 */

#pragma once

#include <type_traits>
#include <istream>
#include <ostream>
#include <vector>
#include <string>
#include <array>
#include <list>

#include <molog/mologexcept.hpp>
#include <molog/serializer/endianness.hpp>
#include <molog/foreach.hpp>


#ifdef MOLOG_ENABLE_DB_COMPABILITIES
 #define __MO_CONVERT_ENDIANNESS u = Endian::convertToPreferredEndianness(u)
#else
 #define __MO_CONVERT_ENDIANNESS do {} while(0)
#endif

#define __MO_SERIALIZE_HELPER_D__(field) Molog::Serde::deserialize(input, u.field);
#define __MO_SERIALIZE_HELPER_S__(field) Molog::Serde::serialize(output, u.field);

#define MO_SERDE_GENERATE(T, ...) \
friend struct Molog::__serde<T>; \
\
inline friend void __p_serde__deserialize(std::istream& input, T& u) { \
    MO_EXPAND(MO_FOR_EACH_P0(__MO_SERIALIZE_HELPER_D__, __VA_ARGS__)) \
} \
 \
inline friend void __p_serde__serialize(std::ostream& output, const T& u) { \
    MO_EXPAND(MO_FOR_EACH_P0(__MO_SERIALIZE_HELPER_S__, __VA_ARGS__)) \
}

namespace Molog
{
    template<typename T>
    struct __serde
    {
        constexpr __serde() {}

        inline void deserialize(std::istream& input, T& u) const {
            __p_serde__deserialize(input, u);
        }

        inline void serialize(std::ostream& output, const T& u) const {
            __p_serde__serialize(output, u);
        }
    };

    template<> struct __serde<bool> { inline void deserialize(std::istream& input, bool& u) const { input.read((char*) &u, sizeof(bool)); __MO_CONVERT_ENDIANNESS; } inline void serialize(std::ostream& output, bool u) const { __MO_CONVERT_ENDIANNESS; output.write((const char*) &u, sizeof(bool)); }};
    template<> struct __serde<float> { inline void deserialize(std::istream& input, float& u) const { input.read((char*) &u, sizeof(float)); __MO_CONVERT_ENDIANNESS; } inline void serialize(std::ostream& output, float u) const { __MO_CONVERT_ENDIANNESS; output.write((const char*) &u, sizeof(float)); }};
    template<> struct __serde<char> { inline void deserialize(std::istream& input, char& u) const { input.read((char*) &u, sizeof(char)); __MO_CONVERT_ENDIANNESS; } inline void serialize(std::ostream& output, char u) const { __MO_CONVERT_ENDIANNESS; output.write((const char*) &u, sizeof(char)); }};
    template<> struct __serde<double> { inline void deserialize(std::istream& input, double& u) const { input.read((char*) &u, sizeof(double)); __MO_CONVERT_ENDIANNESS; } inline void serialize(std::ostream& output, double u) const { __MO_CONVERT_ENDIANNESS; output.write((const char*) &u, sizeof(double)); }};
    template<> struct __serde<uint8_t> { inline void deserialize(std::istream& input, uint8_t& u) const { input.read((char*) &u, sizeof(uint8_t)); __MO_CONVERT_ENDIANNESS; } inline void serialize(std::ostream& output, uint8_t u) const { __MO_CONVERT_ENDIANNESS; output.write((const char*) &u, sizeof(uint8_t)); }};
    template<> struct __serde<uint16_t> { inline void deserialize(std::istream& input, uint16_t& u) const { input.read((char*) &u, sizeof(uint16_t)); __MO_CONVERT_ENDIANNESS; } inline void serialize(std::ostream& output, uint16_t u) const { __MO_CONVERT_ENDIANNESS; output.write((const char*) &u, sizeof(uint16_t)); }};
    template<> struct __serde<uint32_t> { inline void deserialize(std::istream& input, uint32_t& u) const { input.read((char*) &u, sizeof(uint32_t)); __MO_CONVERT_ENDIANNESS; } inline void serialize(std::ostream& output, uint32_t u) const { __MO_CONVERT_ENDIANNESS; output.write((const char*) &u, sizeof(uint32_t)); }};
    template<> struct __serde<uint64_t> { inline void deserialize(std::istream& input, uint64_t& u) const { input.read((char*) &u, sizeof(uint64_t)); __MO_CONVERT_ENDIANNESS; } inline void serialize(std::ostream& output, uint64_t u) const { __MO_CONVERT_ENDIANNESS; output.write((const char*) &u, sizeof(uint64_t)); }};
    template<> struct __serde<int8_t> { inline void deserialize(std::istream& input, int8_t& u) const { input.read((char*) &u, sizeof(int8_t)); __MO_CONVERT_ENDIANNESS; } inline void serialize(std::ostream& output, int8_t u) const { __MO_CONVERT_ENDIANNESS; output.write((const char*) &u, sizeof(int8_t)); }};
    template<> struct __serde<int16_t> { inline void deserialize(std::istream& input, int16_t& u) const { input.read((char*) &u, sizeof(int16_t)); __MO_CONVERT_ENDIANNESS; } inline void serialize(std::ostream& output, int16_t u) const { __MO_CONVERT_ENDIANNESS; output.write((const char*) &u, sizeof(int16_t)); }};
    template<> struct __serde<int32_t> { inline void deserialize(std::istream& input, int32_t& u) const { input.read((char*) &u, sizeof(int32_t)); __MO_CONVERT_ENDIANNESS; } inline void serialize(std::ostream& output, int32_t u) const { __MO_CONVERT_ENDIANNESS; output.write((const char*) &u, sizeof(int32_t)); }};
    template<> struct __serde<int64_t> { inline void deserialize(std::istream& input, int64_t& u) const { input.read((char*) &u, sizeof(int64_t)); __MO_CONVERT_ENDIANNESS; } inline void serialize(std::ostream& output, int64_t u) const { __MO_CONVERT_ENDIANNESS; output.write((const char*) &u, sizeof(int64_t)); }};

    template<typename _Elem, class _Alloc>
    struct __serde<std::vector<_Elem, _Alloc>>
    {
        inline void deserialize(std::istream& input, std::vector<_Elem, _Alloc>& u) const
        {
            uint_t size = Serde::deserialize<uint_t>(input);
            u.resize(size);
            for(uint_t i = 0; i < size; ++i) Serde::deserialize<_Elem>(input, u[i]);
        }

        inline void serialize(std::ostream& output, const std::vector<_Elem, _Alloc>& u) const
        {
            Serde::serialize<uint_t>(output, (uint_t) u.size());
            for(uint_t i = 0; i < u.size(); ++i) Serde::serialize<_Elem>(output, u[i]);
        }
    };

    template<typename _Elem, class _Alloc>
    struct __serde<std::list<_Elem, _Alloc>>
    {
        inline void deserialize(std::istream& input, std::list<_Elem, _Alloc>& u) const
        {
            uint_t size = Serde::deserialize<uint_t>(input);
            for(uint_t i = 0; i < size; ++i) u.push_back(Serde::deserialize<_Elem>(input)); 
        }

        inline void serialize(std::ostream& output, const std::list<_Elem, _Alloc>& u) const
        {
            Serde::serialize<uint_t>(output, (uint_t) u.size());
            for(const _Elem& elem : u) Serde::serialize<_Elem>(output, elem);
        }

    };

    template<typename _Elem, size_t size_>
    struct __serde<std::array<_Elem, size_>>
    {
        inline void deserialize(std::istream& input, std::array<_Elem, size_>& u) const
        {
            for(uint_t i = 0; i < size_; ++i) Serde::deserialize<_Elem>(input, u[i]);
        }

        inline void serialize(std::ostream& output, const std::array<_Elem, size_>& u) const
        {
            for(uint_t i = 0; i < size_; ++i) Serde::serialize<_Elem>(output, u[i]);
        }
    };

    template<typename _Elem, class _Traits, class _Alloc>
    struct __serde<std::basic_string<_Elem, _Traits, _Alloc>>
    {
        inline void deserialize(std::istream& input, std::basic_string<_Elem, _Traits, _Alloc>& u) const
        {
            uint_t size = Serde::deserialize<uint_t>(input);
            u.resize(size);
            for(uint_t i = 0; i < size; ++i) Serde::deserialize<_Elem>(input, u[i]);
        }

        inline void serialize(std::ostream& output, const std::basic_string<_Elem, _Traits, _Alloc>& u) const
        {
            Serde::serialize<uint_t>(output, (uint_t) u.size());
            for(uint_t i = 0; i < u.size(); ++i) Serde::serialize<_Elem>(output, u[i]);
        }
    };


    class Serde final {
        Serde() = delete;
    public:
        template<typename T>
        static inline void deserialize(std::istream& input, T& u) {
            __serde<T>().deserialize(input, u);
        }

        template<typename T>
        static inline void serialize(std::ostream& output, const T& u) {
            __serde<T>().serialize(output, u);
        }

        template<typename T, typename = std::enable_if<std::is_constructible<T>::value>::type>
        static inline T deserialize(std::istream &input)
        {
            T _u;
            deserialize(input, _u);
            return _u;
        }
    };
}
