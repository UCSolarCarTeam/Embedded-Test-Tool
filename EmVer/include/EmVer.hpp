#pragma once

#include "TestSuite.hpp"

class EmVer
{
public:
	EmVer(const std::vector<TestSuite> testSuites);
	void start();

private:
	std::vector<TestSuite> testSuites_;
	char commandBuf_[256];
};