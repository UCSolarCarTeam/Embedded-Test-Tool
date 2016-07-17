#pragma once

#include <memory>

#include "I_TestSuite.hpp"

class I_EmVerWriter;

class EmVer
{
public:
    EmVer(std::vector<std::shared_ptr<I_TestSuite>>& testSuites, I_EmVerWriter& writer);
    void start();

private:
    std::string indentMessage(const std::string& s);
    std::vector<std::shared_ptr<I_TestSuite>> testSuites_;
    I_EmVerWriter& writer_;
};
