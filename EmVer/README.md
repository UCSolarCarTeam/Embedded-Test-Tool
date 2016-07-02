# Embedded Test Tool

This is an embedded system testing tool which is powered by an MBED LPC1768.
It is built by the University of Calgary Solar Car Team with the purpose of testing the Gen 5 Solar Car embedded systems.
The embedded test tool will send out signals connected to a different board, and check the signals coming back.
The test MBED is controlled via serial and will output pass, fail, and information messages based on how the target board handled the inputs.

## Compiling

To compile, you will need the `arm-none-eabi-g++` compiler.
You can get it from https://github.com/adamgreen/gcc4mbed.
Run whichever installer script matches your OS, then run the `BuildShell` script.
This will temporarily add the compiler to your PATH, you can then compile.
You can use the `makeall.sh` script to compile both the tests and source and then run the tests.
To only compile, simply run `make` in the root directory. 

## Running

After compiling the source, a `EmbeddedTestTool.bin` will be created in the root directory.
Connect an mbed LPC1768 to your computer and copy `EmbeddedTestTool.bin` into the root directory of the MBED. 
To interact with the program, you will need to connect to the MBED's serial port, you can do this with [PuTTy](http://www.chiark.greenend.org.uk/~sgtatham/putty/download.html).

Once you are connected, press `ENTER` to receive output from the program, afterwards follow the onscreen instructions.

## Testing

Testing the CCS Test Tool is done with googletest and googlemock, the gmock and gtest header files need to be in /usr/local/include.
You must compile the library that has the definitions yourself.
Meaning you need a `libgmock.a` archive file in the test directory in order to compile the tests.

To create a `libgmock.a` file follow these instructions in an arbitrary dir.

1. Get the googletest and googlemock source code:
    `git clone https://github.com/google/googletest.git`

2. Go into the cloned directory
    `cd googletest/`

3. Compile googletest:[]
    `g++ -isystem googletest/include/ -Igoogletest -isystem googlemock/include/ -Igooglemock -pthread -c googletest/src/gtest-all.cc`

4. Compile googlemock:
    `g++ -isystem googletest/include/ -Igoogletest -isystem googlemock/include/ -Igooglemock -pthread -c googlemock/src/gmock-all.cc`

5. Collect both the resulting .o files into an archive file:
    `ar -rv libgmock.a gtest-all.o gmock-all.o`

Congratulations! You now have a `libgmock.a` archive file, now include it in the `Schulich-Delta-CCS-Test-Tool/test/` directory and you should be good to go, run `make` in the test directory to check if you can compile the tests.
