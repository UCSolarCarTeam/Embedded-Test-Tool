#pragma once

class I_EmVerWriter
{
public:
    virtual ~I_EmVerWriter() {}
    virtual void print(std::string msg) = 0;
    virtual void println(std::string msg) = 0;
};
