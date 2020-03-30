CXXFLAGS = -std=c++17

main: main.o Stack.o List.o Node.o
	g++ -o main main.o Stack.o List.o Node.o

tests: tests.o Stack.o List.o Node.o
	g++ -o tests tests.o Stack.o List.o Node.o

main.o: main.cpp Stack.h List.h Node.h
	g++ -c main.cpp

$(OBJS).o: Stack.cpp Stack.h List.cpp List.h Node.cpp Node.h
	g++ -c Stack.cpp List.cpp Node.cpp

tests.o: tests.cpp Stack.h List.h Node.h
	g++ -c tests.cpp

clean:
	rm *.o main tests 

