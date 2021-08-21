/**
 * @file assertion.hpp
 * @author Guillaume Boyé
 * @version 0.1.1
 * @date 2021-08-21
 * 
 * @copyright MIT License
 * Copyright (c) 2021 Guillaume Boyé
 * 
 */

#pragma once

#include <exception>
#include <string>

#include <molog/mologexcept.hpp>
#include <molog/exception.hpp>
#include <molog/foreach.hpp>


/**
 * @brief force the assertion of a condition (both in release and debug mode). If the condition failed then throw Molog::Exception
 * 
 * @note We highly recommand the usage of #MO_ASSERT(condition,...) over #MO_FORCE_ASSERT(condition,...) as the first macro is conditionned by the option #MOLOG_VALIDATION_LAYER and therefore
 * can be disabled in Release configuration
 */
#define MO_FORCE_ASSERT(condition, ...)                                                            do { if(!(condition)){ MO_THROW_EXCEPTION("assertion failed " MO_STRINGIZE(condition) ": ", ##__VA_ARGS__); }} while(0)

/**
 * @brief assert that the given pointer is not null. if it is the case throw Molog::Exception 
 * 
 * @note We highly recommand the usage of #MO_ASSERT_NON_NULL(ptr,...) over #MO_FORCE_ASSERT_NON_NULL(ptr,...) as the first macro is conditionned by the option #MOLOG_VALIDATION_LAYER and therefore
 * can be disabled in Release configuration
 */
#define MO_FORCE_ASSERT_NON_NULL(ptr, ...)                                                         MO_FORCE_ASSERT(ptr != nullptr, "NullPointerException ", ##__VA_ARGS__)

/**
 * @brief assert that the given pointer is not null. if it is the case throw Molog::Exception 
 * 
 * @note We highly recommand the usage of #MO_ASSERT_NULL(ptr,...) over #MO_FORCE_ASSERT_NULL(ptr,...) as the first macro is conditionned by the option #MOLOG_VALIDATION_LAYER and therefore
 * can be disabled in Release configuration
 */
#define MO_FORCE_ASSERT_NULL(ptr, ...)                                                             MO_FORCE_ASSERT(ptr == nullptr, "PointerAlreadyUsedException", ##__VA_ARGS__)

/**
 * @brief assert that the given pointer is not null. if it is the case throw Molog::Exception 
 * 
 * @note We highly recommand the usage of #MO_ASSERT_RETURN_SUCCESS(op,...) over #MO_FORCE_ASSERT_RETURN_SUCCESS(op,...) as the first macro is conditionned by the option #MOLOG_VALIDATION_LAYER and therefore
 * can be disabled in Release configuration. Notice that even when #MOLOG_VALIDATION_LAYER is not set the #MO_ASSERT_RETURN_SUCCESS perform the operation only the check of the return is not performed
 */
#define MO_FORCE_ASSERT_RETURN_SUCCESS(op, ...)                                                    MO_FORCE_ASSERT(op == MO_SUCCESS, "OperationFailedException", ##__VA_ARGS__)

#if defined(MOLOG_VALIDATION_LAYER)
 /// @copydoc MO_FORCE_ASSERT
 #define MO_ASSERT(condition, ...)                                                                 MO_FORCE_ASSERT(condition, ##__VA_ARGS__)
 
 /// @copydoc MO_FORCE_ASSERT_NON_NULL
 #define MO_ASSERT_NON_NULL(ptr, ...)                                                              MO_FORCE_ASSERT_NON_NULL(ptr, ##__VA_ARGS__)
 
 /// @copydoc MO_FORCE_ASSERT_NULL
 #define MO_ASSERT_NULL(ptr, ...)                                                                  MO_FORCE_ASSERT_NULL(ptr, ##__VA_ARGS__)
 
 /// @copydoc MO_FORCE_ASSERT_RETURN_SUCCESS
 #define MO_ASSERT_RETURN_SUCCESS(op, ...)                                                         MO_FORCE_ASSERT_RETURN_SUCCESS(op, ##__VA_ARGS__)
#else
 /// @copydoc MO_FORCE_ASSERT
 #define MO_ASSERT(condition, ...)

 /// @copydoc MO_FORCE_ASSERT_NON_NULL
 #define MO_ASSERT_NON_NULL(ptr, ...)

 /// @copydoc MO_FORCE_ASSERT_NULL
 #define MO_ASSERT_NULL(ptr, ...)

 /// @copydoc MO_FORCE_ASSERT_RETURN_SUCCESS
 #define MO_ASSERT_RETURN_SUCCESS(op, ...)                                                         do { op; } while(0)
#endif


