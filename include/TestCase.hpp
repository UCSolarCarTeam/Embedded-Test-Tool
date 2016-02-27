#ifndef TESTCASE_HPP
#define TESTCASE_HPP

#include <string>

#include "TestResult.hpp"

class TestCase
{
public:
    virtual TEST_RESULT run() = 0;
    std::string getTestName() const;
protected:
    // virtual void setup() = 0;
    // virtual void tearDown() = 0;
    std::string testName;
};

#endif // TEST_HPP

