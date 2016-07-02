#ifndef TEST_SUITE_HPP
#define TEST_SUITE_HPP

#include <string>
#include <map>
#include <iterator>
#include <vector>

#include "TestCase.hpp"

class TestSuite
{
public:
    std::vector<std::string> runTests() const;
    void addTestCase(TestCase* testCase);
    std::vector<std::string> runTest(std::string name);
    std::map<std::string, TestCase*>::const_iterator getBegin() const;
    std::map<std::string, TestCase*>::const_iterator getEnd() const;

protected:
    std::map<std::string, TestCase*> testCases;
};

#endif // TEST_SUITE_HPP
