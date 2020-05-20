CXXFLAGS = -std=c++17

main: main.o queens.o 
	g++ -o main main.o queens.o

tests: tests.o queens.o 
	g++ -o tests tests.o queens.o


main.o: main.cpp queens.h
	g++ -c main.cpp

queens.o: queens.cpp queens.h
	g++ -c queens.cpp

tests.o: tests.cpp queens.h 
	g++ -c tests.cpp

clean:
	rm *.o 

