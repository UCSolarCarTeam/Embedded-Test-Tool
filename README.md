# Schulich-Delta-CCS-Test-Tool
This test MBED code aims to simulate input values for the CCS.
These values wil be ones the CCS would typically expect from Schulich Delta.
The test MBED will then return output values or pass/fail based on how the CCS handled the inputs.

## Testing

Testing the CCS Test Tool is done with googletest and googlemock, the gmock and gtest header files need to be in /usr/local/include.
You must compile the library that has the definitions yourself.
Meaning you need a `libgmock.a` archive file in the test directory in order to compile the tests.

To create a `libgmock.a` file follow these instructions in an arbitrary dir.

1. Get the googletest and googlemock source code:
    `git clone https://github.com/google/googletest.git`

2. Go into the cloned directory
    `cd googletest/`

3. Compile googletest:
    `g++ -isystem googletest/include/ -Igoogletest -isystem googlemock/include/ -Igooglemock -pthread -c googletest/src/gtest-all.cc`

4. Compile googlemock:
    `g++ -isystem googletest/include/ -Igoogletest -isystem googlemock/include/ -Igooglemock -pthread -c googlemock/src/gmock-all.cc`

5. Collect both the resulting .o files into an archive file:
    `ar -rv libgmock.a gtest-all.o gmock-all.o`

Congratulations! You now have a `libgmock.a` archive file, now include it in the `Schulich-Delta-CCS-Test-Tool/test/` directory and you should be good to go, run `make` in the test directory to check if you can compile the tests.
