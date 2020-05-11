CXXFLAGS = -std=c++17

main: main.o median.o 
	g++ -o main main.o median.o

$(OBJS).o: median.cpp Heap.h 

main.o: main.cpp median.h 

clean:
	rm *.o main 

