#pragma once

#include "TestSuite.hpp"

class I_EmVerWriter;

class EmVer
{
public:
    EmVer(const std::vector<TestSuite>& testSuites, I_EmVerWriter& writer);
    void start();

private:
    std::vector<TestSuite> testSuites_;
    I_EmVerWriter& writer_;
};
