#ifndef TESTCASE_HPP
#define TESTCASE_HPP

#include <string>

class TestCase
{
public:
    virtual std::string run() const = 0;
    virtual std::string getTestName() const = 0;
protected:
    // virtual void setup() = 0;
    // virtual void tearDown() = 0;
    std::string testName;
};

#endif // TEST_HPP
