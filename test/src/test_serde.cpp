#include <gtest/gtest.h>
#include <molog/serializer/serializer.hpp>
#include <molog/assertion.hpp>
#include <sstream>

MO_USE_NAMESPACE;

TEST(MoSerde, SerdeBaseType) {
    std::stringstream ss;
    Serde::serialize<uint32_t>(ss, 50);
    EXPECT_EQ(Serde::deserialize<uint32_t>(ss), 50);
    
    Serde::serialize<uint32_t>(ss, 29);
    EXPECT_EQ(Serde::deserialize<uint32_t>(ss), 29);
}

TEST(MoSerde, SerdeVector) {
    std::stringstream ss;
    std::vector<int> a = {80, 20, 30, 80, 60};
    Serde::serialize(ss, a);
    std::vector<int> b = Serde::deserialize<std::vector<int>>(ss);

    for(int i = 0; i < a.size(); ++i) {
        EXPECT_EQ(a[i], b[i]);
    }
}

TEST(MoSerde, SerdeString) {
    std::stringstream ss;
    std::string r = "test, hello world";
    Serde::serialize(ss, r);

    std::string b = Serde::deserialize<std::string>(ss);
    EXPECT_STREQ(r.c_str(), b.c_str());
}

TEST(MoSerde, SerdeArray) {
    std::stringstream ss;
    std::array<int,5> a = {1, 5, 9, 3, 2};
    Serde::serialize(ss, a);

    std::array<int,5> b = Serde::deserialize<std::array<int,5>>(ss);
    for(int i = 0; i < a.size(); ++i) {
        EXPECT_EQ(a[i], b[i]);
    }
}

TEST(MoSerde, SerdeList) {
    std::stringstream ss;
    std::list<unsigned long long> a_ = {80, 20, 30, 80, 60};
    Serde::serialize(ss, a_);
    std::list<unsigned long long> b_ = Serde::deserialize<std::list<unsigned long long>>(ss);

    std::vector<unsigned long long> a(a_.begin(), a_.end());
    std::vector<unsigned long long> b(b_.begin(), b_.end());

    for(int i = 0; i < a.size(); ++i) {
        EXPECT_EQ(a[i], b[i]);
    }
}

struct __Struct {
    int a, b, c;
    std::string d;
    std::vector<std::string> e;

    MO_SERDE_GENERATE(__Struct, a, b, c, d, e);

    inline bool operator==(const __Struct& over) {
        if(!(a == over.a &&
            b == over.b &&
            c == over.c &&
            d == over.d)) return false;

        if(e.size() != over.e.size()) return false;
        for (uint_t i = 0; i < e.size(); i++) {
            if(e[i] != over.e[i]) return false;
        }
        return true;
    }
};

TEST(MoSerde, SerdeGeneration) {
    __Struct a;
    a.a = 58;
    a.b = 15;
    a.c = 98;
    a.d = "I love baked potatoe";
    a.e = { "cd test", "mkdir src && mkdir build", "tmux", "Ctrl+\"" };

    std::stringstream ss;
    Serde::serialize(ss, a);
    __Struct b = Serde::deserialize<__Struct>(ss);

    EXPECT_TRUE(a == b);
}
