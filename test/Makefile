OBJS = $(wildcard src/*.cpp) ../src/TestSuite.cpp

COMPILE_FLAGS = -g -std=c++11 -Werror

LINK_FLAGS = -pthread

OUTPUT_NAME = RunTests

INCLUDE_FLAGS = -I../include -Ilib

all :
	 $(CXX) -isystem gtest_include -isystem gmock_include $(INCLUDE_FLAGS) $(OBJS) $(LINK_FLAGS) $(COMPILE_FLAGS) libgmock.a -o $(OUTPUT_NAME)

clean :
	rm $(OUTPUT_NAME)
