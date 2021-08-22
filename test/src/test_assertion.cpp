#include <gtest/gtest.h>

#include <molog/configure.hpp>
#ifdef MOLOG_VALIDATION_LAYER
 #undef MOLOG_VALIDATION_LAYER
#endif
#include <molog/assertion.hpp>

class custom_exception : public std::exception {};

volatile int throw_op()
{
    throw custom_exception();
}

volatile int op_re(int code)
{
    return code;
}

TEST(MoAssertion, BasicAssert)
{
    volatile bool x = false;
    EXPECT_NO_THROW(MO_FORCE_ASSERT(true));
    EXPECT_NO_THROW(MO_FORCE_ASSERT(1 + 1 == 2, "random issue"));
    EXPECT_NO_THROW(MO_FORCE_ASSERT(!x, "str1", "r2"));

    EXPECT_THROW(MO_FORCE_ASSERT(false), Molog::Exception);
    EXPECT_THROW(MO_FORCE_ASSERT(x, "str1, std2", "zrggr", "zrgre000"), Molog::Exception);
}

TEST(MoAssertion, ForceAssertion)
{
    void *nptr = nullptr, *ptr = (void*) 0x1;
    EXPECT_NO_THROW(MO_FORCE_ASSERT_NULL(nptr));
    EXPECT_NO_THROW(MO_FORCE_ASSERT_NON_NULL(ptr));
    EXPECT_THROW(MO_FORCE_ASSERT_NULL(ptr), Molog::Exception);
    EXPECT_THROW(MO_FORCE_ASSERT_NON_NULL(nptr), Molog::Exception);
    
    EXPECT_NO_THROW(MO_FORCE_ASSERT_RETURN_SUCCESS(MO_SUCCESS));
    EXPECT_THROW(MO_FORCE_ASSERT_RETURN_SUCCESS(MO_FAILURE), Molog::Exception);

    EXPECT_THROW(MO_ASSERT_RETURN_SUCCESS(throw_op()), custom_exception);
    EXPECT_NO_THROW(MO_ASSERT_RETURN_SUCCESS(op_re(MO_SUCCESS)));
    EXPECT_NO_THROW(MO_ASSERT_RETURN_SUCCESS(op_re(MO_FAILURE)));
}
