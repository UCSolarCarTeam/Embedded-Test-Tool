#include "TestCase.hpp"

class DummyTestB : public TestCase
{
public:
    std::string run() const
    {
        return " ";
    }

    std::string getTestName() const
    {
        return "DummyTestB";
    }

};
