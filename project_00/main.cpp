#include <iostream>
#include "myVector.h"

using namespace std;

int main() {
    myVector<int> t;
    
    std::cout << "t size: " << t.size() << std::endl;
    std::cout << "t capacity: " << t.get_capacity() << std::endl;
    std::cout << std::endl;
    
    for (int i = 0; i < 99; i++) {
        t.push(i);
    }
    
    t.push(99);
    
    std::cout << "t size: " << t.size() << std::endl;
    std::cout << "t capacity: " << t.get_capacity() << std::endl;
    std::cout << std::endl;
    
    t.print();
    
    for (int i = 100; i < 121; i++) {
        t.push(i);
    }
    
    std::cout << std::endl;
    std::cout << "check [] operator" << std::endl;
    std::cout << "t[100] = " << t[100] << std::endl;
    std::cout << std::endl;
    
    t[100] = 79;

    std::cout << "assign t[100] = 79" << std::endl;
    std::cout << "t[100] = " << t[100] << std::endl;
    std::cout << std::endl;
    
    t.print();
}

