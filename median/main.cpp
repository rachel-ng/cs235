#include <iostream>
#include <cstdlib>
#include <ctime>
#include "median.h"

int main () {
    std::srand(std::time(nullptr));

    int size = 9 + (std::rand() % (1 + 1));

    double a [size];
    for (int i = 0; i < size; i++) {
        a[i] = std::rand() % (10);
    }

    prnt(a,size);
    std::cout << std::endl;

    std::cout << "median" << std::endl;
    std::cout << median(a, size) << std::endl;
    
    std::cout << "\n" << std::endl;

    minheapsort(a,size);
    prnt(a,size);
    prnt_i(a,size);
    
    return 1;

}

