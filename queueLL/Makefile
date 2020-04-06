CXXFLAGS = -std=c++17

main: main.o Queue.o Node.o
	g++ -o main main.o Queue.o Node.o

tests: tests.o Queue.o Node.o
	g++ -o tests tests.o Queue.o Node.o

main.o: main.cpp Queue.h Node.h
	g++ -c main.cpp

$(OBJS).o: Queue.cpp Queue.h Node.cpp Node.h
	g++ -c Queue.cpp Node.cpp

tests.o: tests.cpp Queue.h Node.h
	g++ -c tests.cpp

clean:
	rm *.o main tests 

