CXXFLAGS = -std=c++17

main: main.o Heap.o 
	g++ -o main main.o Heap.o

$(OBJS).o: Heap.cpp Heap.h 

main.o: main.cpp Heap.h 

clean:
	rm *.o main 

