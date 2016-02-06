#ifndef TEST_SUITE_HPP
#define TEST_SUITE_HPP

#include "TestCase.hpp"
#include <vector>

class TestSuite
{
public:
    virtual void runTests() = 0;
protected:
    std::vector<TestCase> testCases;
};

#endif // TEST_SUITE_HPP
