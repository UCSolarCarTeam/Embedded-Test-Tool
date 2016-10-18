#include <string>

#include "EmVerWriter.hpp"

EmVerWriter::EmVerWriter()
    : pc_(new Serial(USBTX, USBRX))
{
    LocalFileSystem local("local");
    fp_ = fopen("/local/TestResult.txt", "w");
    pc_->baud(9600);
}

EmVerWriter::~EmVerWriter()
{
    fclose(fp_);
}

void EmVerWriter::print(std::string msg)
{
    fprintf(fp_, msg.c_str());
    pc_->printf(msg.c_str());
}

void EmVerWriter::println(std::string msg)
{
    print(msg + "\n");
}
