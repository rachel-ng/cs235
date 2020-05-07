#include <iostream>
#include <cmath>
#include "Heap.h"

void prnt (int arry[], int size) {
    std::cout << arry[0];
    for (int i = 1; i < size; i++) {
        std::cout << ", " << arry[i];
    }
    std::cout << std::endl;
}

void prnt_i (int arry[], int size) {
    std::cout << arry[size - 1];
    for (int i = size - 2; i > -1; i--) {
        std::cout << ", " << arry[i];
    }
    std::cout << std::endl;
}

void heapify (int arry[], int size) {
    for (int i = 1; i < size; i++) {
        siftup(arry, i, size);
    }
}

void siftup(int arry[], int n, int size) {
    int parent = floor((n-1)/2);
    int val = arry[n];
    
    //std::cout << n << " (" << arry[n] << ") -> ";

    while (n >= 0 && arry[parent] > arry[n] && parent > -1) {
        arry[n] = arry[parent];
        arry[parent] = val;
        n = parent;
        parent = floor((n-1)/2);
        val = arry[n];
    }

    //std::cout << n << " (" << arry[n] << ")" << std::endl;
    //prnt(arry, 15);
    //std::cout << std::endl;
}

int removemin (int arry[], int size) { 
    int val = arry[size-1];

    arry[size-1] = arry[0];
    arry[0] = val;
   
    heapify(arry, size - 1);

    return arry[size-1];
}

void heapsort (int arry[], int size) {
    for (int i = 1; i < size; i++) {
        siftup(arry, i, size);
    }
    
    for(int i = 0; i < size; i++) {
        removemin(arry, size - i);
    }
}

