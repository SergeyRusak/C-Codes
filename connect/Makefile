CXX=g++
CFLAGS=-c -Wall --std=c++11

all: prog1 prog2

prog1:
	$(CXX) $(CFLAGS) prog1.cpp -o prog1
	chmod +x prog1

prog2:
	$(CXX) $(CFLAGS) prog2.cpp -o prog2
	chmod +x prog2

run: all
	./prog1 5
	./prog2
