EXENAME = main
TEST = test
OBJS = main.o


CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

.PHONY: all test clean output_msg

all : $(EXENAME)


output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME) : output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp algorithms.h read_airport.h read_routes.h
	$(CXX) $(CXXFLAGS) main.cpp

algorithms.o : algorithms.cpp algorithms.h read_airport.h read_routes.h
	$(CXX) $(CXXFLAGS) algorithms.cpp

read_airport.o: read_airport.cpp read_airport.h
	$(CXX) $(CXXFLAGS) read_airport.cpp

read_routes.o: read_routes.cpp read_routes.h read_airport.h
	$(CXX) $(CXXFLAGS) read_routes.cpp

test: output_msg catchmain.o test_1.o
	$(LD) catchmain.o test_1.o $(LDFLAGS) -o test

catchmain.o : catch/catchmain.cpp catch/catch.hpp
	$(CXX) $(CXXFLAGS) catch/catchmain.cpp

test_1.o : tests/test_1.cpp catch/catch.hpp algorithms.h read_airport.h read_routes.h
	$(CXX) $(CXXFLAGS) tests/test_1.cpp

clean :
	-rm -f *.o .txt $(EXENAME) test