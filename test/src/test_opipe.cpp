#include <gtest/gtest.h>
#include <molog/logger/opipe.hpp>
#include <molog/assertion.hpp>

#include <sstream>
MO_USE_NAMESPACE;

TEST(MoOPipe, Fn_StreamToPipeImpl) {
    std::stringstream ss;
    bool _isOpen = false;

    auto& pipe = OPipe(streamToPipeImpl(ss, [&_isOpen](){ return _isOpen; }, "random", nullptr));
    
    EXPECT_FALSE(pipe.isOpen());
    EXPECT_TRUE(pipe.isClosed());
    EXPECT_FALSE(pipe.isClosable());
    // EXPECT_FALSE(pipe.isColorized()); 

    _isOpen = true;
    EXPECT_TRUE(pipe.isOpen());
    EXPECT_FALSE(pipe.isClosed());
    EXPECT_FALSE(pipe.isClosable());

    const char* test = "hello, world";
    pipe.write(test, strlen(test));
    pipe.setThrowOnError(false);
    EXPECT_NO_THROW(pipe.close());
    EXPECT_NO_THROW(pipe.open());
    pipe.setThrowOnError(true);
    EXPECT_THROW(pipe.close(), Exception);

    EXPECT_STREQ(ss.str().c_str(), test);
}

TEST(MoOPipe, Fn_StdPipe) {
    const char* test = "if you see this message then everything is fine\n";
    stdpipe.write(test, strlen(test));
}
