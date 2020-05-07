#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Heap.h"

int main () {
    std::srand(std::time(nullptr));

    int a [15];
    for (int i = 0; i < 15; i++) {
        a[i] = std::rand() % (30 + 1);
    }

    prnt(a,15);
    std::cout << std::endl;

    heapify(a, 15);

    std::cout << "heapify" << std::endl;
    prnt(a,15);
    std::cout << std::endl;
    
    heapsort(a, 15);
    
    std::cout << "heapsort" << std::endl;
    prnt(a,15);
    prnt_i(a,15);
    
    return 1;

}

