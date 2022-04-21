all: hello

hello: main.o NDArray.o 
	g++ main.o NDArray.o -o hello

main.o: main.cpp
	g++ -c main.cpp

NDArray.o: NDArray.cpp
	g++ -c NDArray.cpp

clean:
	rm -rf *.o hello
run: hello
	./hello
