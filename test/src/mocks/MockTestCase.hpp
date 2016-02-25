#include <string>

#include "gmock/gmock.h"

#include "TestCase.hpp"
#include "TestResult.hpp"

class MockTestCase : public TestCase {
public:
    MOCK_METHOD0(run, TEST_RESULT());
    MOCK_CONST_METHOD0(getTestName, std::string());
};
