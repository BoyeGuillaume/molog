#include <gtest/gtest.h>
#include <molog/logger/logger.hpp>
#include <molog/logger/pipe.hpp>
#include <molog/assertion.hpp>

#include <string>

MO_USE_NAMESPACE;

TEST(MoFiles, FWriteRead) {
    std::shared_ptr<OPipe> p = fopen_w("test.txt", false);
    
    std::string s = "hello and welcome";
    p->write(s.data(), s.size());
    p->write(Endl);
    p->close();

    std::shared_ptr<IPipe> i = fopen_r("test.txt");
    std::string buffer;
    buffer.resize(500);
    uint_t size = i->read(buffer.data(), buffer.size());
    buffer = buffer.substr(0, size);
    EXPECT_STREQ(buffer.c_str(), (s + "\n").c_str());  
}

TEST(MoFiles, FWriteReadBinary) {
    std::shared_ptr<OPipe> p = fopen_w("test.txt", false);
    
    std::string t(256, '\0');
    for(uint_t i=0; i<256; ++i) {
        t[i] = (char) i;
    }

    p->write(t.data(), t.size());
    p->write(Flush);
    p->close();

    std::shared_ptr<IPipe> i = fopen_r("test.txt");
    std::string buffer;
    buffer.resize(500);
    uint_t size = i->read(buffer.data(), buffer.size());
    buffer = buffer.substr(0, size);
    EXPECT_EQ(buffer, t);  
}
