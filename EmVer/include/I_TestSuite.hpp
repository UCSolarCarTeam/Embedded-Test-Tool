#pragma once

#include <string>
#include <vector>

#include "TestCase.hpp"

class I_TestSuite
{
public:
    virtual ~I_TestSuite() {}
    virtual int totalTestCases() const = 0;
    virtual std::string name() const = 0;
    virtual std::string testCaseName(unsigned int i) const = 0;
    virtual std::string runTestCase(unsigned int i) const = 0;
};
