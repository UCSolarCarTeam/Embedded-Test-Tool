#pragma once

#include "I_EmVerWriter.hpp"

class MockEmVerWriter : public I_EmVerWriter
{
public:
    MockEmVerWriter()
    : output_("")
    {}

    ~MockEmVerWriter() {}

    void print(std::string msg)
    {
        output_ += msg;
    }

    void println(std::string msg)
    {
        output_ += msg + "\n";
    }

    std::string output()
    {
        return output_;
    }

private:
    std::string output_;
};
