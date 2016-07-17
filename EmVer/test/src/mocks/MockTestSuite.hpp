#include <string>

#include <gmock/gmock.h>

#include "I_TestSuite.hpp"

class MockTestSuite : public I_TestSuite
{
public:
    MOCK_CONST_METHOD0(totalTestCases, int());
    MOCK_CONST_METHOD0(name, std::string());
    MOCK_CONST_METHOD1(testCaseName, std::string(unsigned int));
    MOCK_CONST_METHOD1(runTestCase, std::string(unsigned int));
};
