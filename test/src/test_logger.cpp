#include <gtest/gtest.h>
#include <molog/logger/logger.hpp>
#include <molog/logger/pipe.hpp>
#include <molog/assertion.hpp>

#include <string>

MO_USE_NAMESPACE;


TEST(MoLogger, StdLogger) {
    stdlogger.log(Severity::Warning) << "Hello, World";
}
