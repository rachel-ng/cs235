CXXFLAGS = -std=c++17

main: main.o List.o Node.o
	g++ -o main main.o List.o Node.o

tests: tests.o List.o Node.o
	g++ -o tests tests.o List.o Node.o

main.o: main.cpp List.h Node.h

$(OBJS).o: List.cpp List.h Node.cpp Node.h

tests.o: tests.cpp List.h Node.h

clean:
	rm *.o main tests 

