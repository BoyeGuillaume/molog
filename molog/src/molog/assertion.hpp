#pragma once

#include <exception>
#include <string>

#include <molog/mologexcept.hpp>
#include <molog/exception.hpp>
#include <molog/foreach.hpp>


#define __MO_EXPAND_STR(str)                                                                       + ((std::string) str)
#define MO_THROW_EXCEPTION(msg, ...)                                                               throw Molog::Exception(msg MO_FOR_EACH_P0(__MO_EXPAND_STR, "", ##__VA_ARGS__))
#define MO_FORCE_ASSERT(condition, ...)                                                            do { if(!(condition)){ MO_THROW_EXCEPTION("assertion failed " MO_STRINGIZE(condition) ": ", ##__VA_ARGS__); }} while(0)
#define MO_FORCE_ASSERT_NON_NULL(ptr, ...)                                                         MO_FORCE_ASSERT(ptr != nullptr, "NullPointerException ", ##__VA_ARGS__)
#define MO_FORCE_ASSERT_NULL(ptr, ...)                                                             MO_FORCE_ASSERT(ptr == nullptr, "PointerAlreadyUsedException", ##__VA_ARGS__)
#define MO_FORCE_ASSERT_RETURN_SUCCESS(op, ...)                                                    MO_FORCE_ASSERT(op == MO_SUCCESS, "OperationFailedException", ##__VA_ARGS__)

#if defined(MOLOG_VALIDATION_LAYER)
 #define MO_ASSERT(condition, ...)                                                                 MO_FORCE_ASSERT(condition, ##__VA_ARGS__)
 #define MO_ASSERT_NON_NULL(ptr, ...)                                                              MO_FORCE_ASSERT_NON_NULL(ptr, ##__VA_ARGS__)
 #define MO_ASSERT_NULL(ptr, ...)                                                                  MO_FORCE_ASSERT_NULL(ptr, ##__VA_ARGS__)
 #define MO_ASSERT_RETURN_SUCCESS(op, ...)                                                         MO_FORCE_ASSERT_RETURN_SUCCESS(op, ##__VA_ARGS__)
#else
 #define MO_ASSERT(condition, ...)
 #define MO_ASSERT_NON_NULL(ptr, ...)
 #define MO_ASSERT_NULL(ptr, ...)
 #define MO_ASSERT_RETURN_SUCCESS(op, ...)                                                         do { op } while(0)
#endif


