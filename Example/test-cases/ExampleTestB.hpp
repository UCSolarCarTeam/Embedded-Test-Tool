#include "TestCase.hpp"

class ExampleTestB : public TestCase
{
public:
    std::string run() const
    {
        return " ";
    }

    std::string getTestName() const
    {
        return "ExampleTestB";
    }

};
