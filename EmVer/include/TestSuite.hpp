#pragma once

#include <string>
#include <vector>

#include "TestCase.hpp"

class TestSuite
{
public:
	TestSuite(std::vector<TestCase*> testCases, std::string name);
	int totalTestCases() const;
	std::string name() const;
	std::string testCaseName(unsigned int i) const;
	std::string runTestCase(unsigned int i) const;

protected:
    std::vector<TestCase*> testCases_;
    std::string name_;
};
