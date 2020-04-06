CXXFLAGS = -std=c++17

main: main.o funcs.o List.o Node.o
	g++ -o main main.o funcs.o List.o Node.o

tests: tests.o funcs.o List.o Node.o
	g++ -o tests tests.o funcs.o List.o Node.o

main.o: main.cpp funcs.h List.h Node.h
	g++ -c main.cpp

$(OBJS).o: funcs.cpp funcs.h List.cpp List.h Node.cpp Node.h
	g++ -c funcs.cpp List.cpp Node.cpp

tests.o: tests.cpp funcs.h List.h Node.h
	g++ -c tests.cpp

clean:
	rm *.o main tests 

