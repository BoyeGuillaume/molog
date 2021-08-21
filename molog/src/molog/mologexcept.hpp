#pragma once

#include <stdexcept>

#include <molog/configure.hpp>



#define __DETAILS_MO_CONCATENATE(a,b)                                                              a ## b
#define __DETAILS_MO_STRINGIZE(x)                                                                  #x
#define MO_EXPAND(x)                                                                               x
#define MO_CONCATENATE(a,b)                                                                        __DETAILS_MO_CONCATENATE(a,b)
#define MO_STRINGIZE(x)                                                                            __DETAILS_MO_STRINGIZE(x)
#define MO_USE_NAMESPACE                                                                           using namespace Molog

#define MO_SUCCESS                                                                                 0
#define MO_FAILURE                                                                                 1

#define MO_PP_NARGS(...)                                                                           MO_PP_NARG_(__VA_ARGS__, MO_PP_RSEQ_N())
#define MO_PP_NARG_(...)                                                                           MO_EXPAND(MO_PP_ARGN(__VA_ARGS__))
#define MO_PP_ARGN(                              \
        _1, _2, _3, _4, _5, _6, _7, _8, _9,_10,  \
        _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
        _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
        _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
        _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
        _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
        _61,_62,_63,N,...)                                                                         N
#define MO_PP_RSEQ_N()                                                                             64,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0

#define MO_DISABLE_COPY(className)                                                                 className(const className&) = delete; \
                                                                                                   className& operator=(const className&) = delete

#define MO_DISABLE_MOVE(className)                                                                 className(className&&) = delete; \
                                                                                                   className& operator=(className&&) = delete

#define MO_DISABLE_COPY_MOVE(className)                                                            MO_DISABLE_COPY(className); \
                                                                                                   MO_DISABLE_MOVE(className)


#if defined(_MSC_VER)
 #define __MO_TARGET_MSC
#elif defined(__GNUC__)
 #define __MO_TARGET_GNUC
#else
 #define __MO_TARGET_UNKNOWN
#endif

#if defined(_WIN32) || defined(_WIN64)
 #define MO_PLATFORM_WINDOW

 #if _WIN64
 #define MO_ENV_x64
 #else
 #define MO_ENV_x86
 #endif

#elif defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
 #define MO_PLATFORM_POSIX

 #if __x86_64__ || __ppc64__
  #define MO_ENV_x64
 #else
  #define MO_ENV_x86
 #endif

#else
 #error Cannot locate the proper platform
#endif

#ifdef MOLOG_BUILD_SHARED
 #if defined(__MO_TARGET_MSC)
  #define __MO_SHARED_EXPORT                                                                       __declspec(dllexport)
  #define __MO_SHARED_IMPORT                                                                       __declspec(dllimport)
 #elif defined(__MO_TARGET_GNUC)
  #define __MO_SHARED_EXPORT                                                                       __attribute__((visibility("default")))
  #define __MO_SHARED_IMPORT
 #else
  #define __MO_SHARED_EXPORT
  #define __MO_SHARED_IMPORT
  #warning "warning unknown dynamic link import/export semantics."
 #endif
 
 #ifdef __MO_DLL_EXPORT
  #define MO_FUNCTION                                                                                __MO_SHARED_EXPORT
 #else
  #define MO_FUNCTION                                                                                __MO_SHARED_IMPORT
 #endif

#else
 #define MO_FUNCTION
#endif

#define MO_CLASS

/**
 * @brief Molog main namespace. All exposed symbols of the molog library are accessible only throught this namespace.
 * Notice that you can use the macro MO_USE_NAMESPACE to use directly the function without having to specified the namespace
 * 
 */
namespace Molog
{
    using flag_t = uint32_t;
    using uint_t = std::size_t;
}
