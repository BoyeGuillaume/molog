#include <gtest/gtest.h>
#include <molog/logger/logger.hpp>
#include <molog/assertion.hpp>

MO_USE_NAMESPACE;


TEST(MoLogger, StdLogger) {
    stdlogger.log(Severity::Warning) << "Hello, World";
}
