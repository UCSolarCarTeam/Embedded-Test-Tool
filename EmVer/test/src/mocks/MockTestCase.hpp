#include <string>

#include <gmock/gmock.h>

#include "TestCase.hpp"

class MockTestCase : public TestCase
{
public:
    MOCK_CONST_METHOD0(run, std::string());
    MOCK_CONST_METHOD0(name, std::string());
};
