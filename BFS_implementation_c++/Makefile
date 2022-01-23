# use g++ with C++11 support
CXX=g++
CXXFLAGS?=-Wall -pedantic -g -O0 -std=c++11
OUTFILES=GraphTest MyTest

all: $(OUTFILES)

GraphTest: GraphTest.cpp Graph.cpp Graph.h
	$(CXX) $(CXXFLAGS) -o GraphTest GraphTest.cpp Graph.cpp

MyTest: MyTest.cpp Graph.cpp Graph.h
	$(CXX) $(CXXFLAGS) -o MyTest MyTest.cpp Graph.cpp

clean:
	$(RM) $(OUTFILES) *.o
