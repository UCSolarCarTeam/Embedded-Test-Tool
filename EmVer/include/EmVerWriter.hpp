#pragma once

#include <memory>

#include "mbed.h"

#include "I_EmVerWriter.hpp"

class EmVerWriter : public I_EmVerWriter
{
public:
    EmVerWriter();
    EmVerWriter(const EmVerWriter&) = delete;
    EmVerWriter& operator=(const EmVerWriter&) = delete;
    ~EmVerWriter();
    void print(std::string msg);
    void println(std::string msg);

private:
    FILE* fp_;
    std::unique_ptr<Serial> pc_;
};
