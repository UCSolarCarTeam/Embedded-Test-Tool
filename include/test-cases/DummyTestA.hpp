#include "TestCase.hpp"

class DummyTestA : public TestCase
{
public:
    std::string run() const
    {
        return "This dummy test failed!";
    }

    std::string getTestName() const
    {
        return "DummyTestA";
    }

};
