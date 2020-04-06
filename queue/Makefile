CXXFLAGS = -std=c++17

main: main.o QueueA.o QueueLL.o Node.o
	g++ -o main main.o QueueA.o QueueLL.o Node.o

tests: tests.o QueueA.o QueueLL.o Node.o
	g++ -o tests tests.o QueueA.o QueueLL.o Node.o

$(OBJS).o: QueueA.cpp QueueA.h QueueLL.cpp QueueLL.h Node.cpp Node.h 

main.o: main.cpp QueueA.h QueueLL.h Node.h

tests.o: tests.cpp QueueA.h QueueLL.h Node.h

clean:
	rm *.o main tests 

