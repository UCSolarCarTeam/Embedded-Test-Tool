#pragma once

#include "mbed.h"

#include "I_EmVerWriter.hpp"

class EmVerWriter : public I_EmVerWriter
{
public:
    EmVerWriter();
    ~EmVerWriter();
    void print(std::string msg);
    void println(std::string msg);

private:
    FILE* fp_;
    Serial* pc_;
};
