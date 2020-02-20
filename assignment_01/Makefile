CXXFLAGS = -std=c++17

main: main.o List.o Node.o
	g++ -o main main.o List.o Node.o

tests: tests.o List.o Node.o
	g++ -o tests tests.o List.o Node.o

main.o: main.cpp List.h Node.h
	g++ -c main.cpp

$(OBJS).o: List.cpp List.h Node.cpp Node.h
	g++ -c List.cpp Node.cpp

tests.o: tests.cpp List.h Node.h
	g++ -c tests.cpp

clean:
	rm *.o main tests 

