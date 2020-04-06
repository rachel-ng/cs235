CXXFLAGS = -std=c++17

main: main.o QueueLL.o Node.o
	g++ -o main main.o QueueLL.o Node.o

tests: tests.o QueueLL.o Node.o
	g++ -o tests tests.o QueueLL.o Node.o

main.o: main.cpp QueueLL.h Node.h
	g++ -c main.cpp

$(OBJS).o: QueueLL.cpp QueueLL.h Node.cpp Node.h
	g++ -c QueueLL.cpp Node.cpp

tests.o: tests.cpp QueueLL.h Node.h
	g++ -c tests.cpp

clean:
	rm *.o main tests 

