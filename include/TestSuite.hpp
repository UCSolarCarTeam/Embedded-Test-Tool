#ifndef TEST_SUITE_HPP
#define TEST_SUITE_HPP

#include <vector>
#include <string>

#include "TestCase.hpp"

class TestSuite
{
public:
    std::string runTests();
    void addTestCase(TestCase* testCase);

protected:
    std::vector<TestCase*> testCases;
};

#endif // TEST_SUITE_HPP
