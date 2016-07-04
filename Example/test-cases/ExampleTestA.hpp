#include "TestCase.hpp"

class ExampleTestA : public TestCase
{
public:
    std::string run() const
    {
        return "This example test failed!";
    }

    std::string name() const
    {
        return "ExampleTestA";
    }

};
