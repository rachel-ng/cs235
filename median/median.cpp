#include <iostream>
#include <cmath>
#include "median.h"


double median (double arry[], int size) {
    int cap = (size / 2) + 1;
    
    double max [cap];
    double min [cap];

    int mins = 1;
    int maxs = 1;
    
    double median = arry[0];
	min[0] = arry[0] > arry[1] ? arry[1] : arry[0];
	max[0] = arry[0] > arry[1] ? arry[0] : arry[1];
    
    for (int i = 2; i < size; i++) {
        double n = arry[i];
        if (mins == maxs) {
            if (n < median && n < max[0]) {
                min[mins] = n;
                mins++;
                minheapsort(min, mins);
                median = min[0];
            }
            else {
                max[maxs] = n;
                maxs++;
                maxheapsort(max, maxs);
                median = max[0];
            }
        }
        else if (mins < maxs) {
            if (median < n) {
                min[mins] = max[0];
                max[0] = n;
                maxheapsort(max,maxs);
            }
            else {
                min[mins] = n;
            }
            mins++;
            minheapsort(min, mins);
            median = (min[0]+max[0])/2;
        }
        else {
            if (median > n) {
                max[maxs] = min[0];
                min[0] = n;
                minheapsort(min,mins);
            }
            else {
                max[maxs] = n;
            }
            maxs++;
            maxheapsort(max,maxs);
            median = (min[0]+max[0])/2;
        }
    }

    return median;
}



void minheapify (double arry[], int size) {
    for (int i = 1; i < size; i++) {
        minsiftup(arry, i, size);
    }
}

void minsiftup(double arry[], int n, int size) {
    int parent = floor((n-1)/2);
    int val = arry[n];
    
    while (n >= 0 && arry[parent] > arry[n] && parent > -1) {
        arry[n] = arry[parent];
        arry[parent] = val;
        n = parent;
        parent = floor((n-1)/2);
        val = arry[n];
    }
}

int removemin (double arry[], int size) { 
    int val = arry[size-1];

    arry[size-1] = arry[0];
    arry[0] = val;
   
    minheapify(arry, size - 1);

    return arry[size-1];
}

void minheapsort (double arry[], int size) {
    minheapify(arry, size);

    for (int i = 1; i < size; i++) {
        minsiftup(arry, i, size);
    }
    
    for(int i = 0; i < size; i++) {
        removemin(arry, size - i);
    }
}

void maxheapify (double arry[], int size) {
    for (int i = 1; i < size; i++) {
        maxsiftup(arry, i, size);
    }
}

void maxsiftup(double arry[], int n, int size) {
    int parent = floor((n-1)/2);
    int val = arry[n];
    
    while (n >= 0 && arry[parent] < arry[n] && parent > -1) {
        arry[n] = arry[parent];
        arry[parent] = val;
        n = parent;
        parent = floor((n-1)/2);
        val = arry[n];
    }
}

int removemax (double arry[], int size) { 
    int val = arry[size-1];

    arry[size-1] = arry[0];
    arry[0] = val;
   
    maxheapify(arry, size - 1);

    return arry[size-1];
}

void maxheapsort (double arry[], int size) {
    maxheapify(arry, size);

    for (int i = 1; i < size; i++) {
        maxsiftup(arry, i, size);
    }
    
    for(int i = 0; i < size; i++) {
        removemax(arry, size - i);
    }
}

void prnt (double arry[], int size) {
    std::cout << arry[0];
    for (int i = 1; i < size; i++) {
        std::cout << ", " << arry[i];
    }
    std::cout << std::endl;
}

void prnt_i (double arry[], int size) {
    std::cout << arry[size - 1];
    for (int i = size - 2; i > -1; i--) {
        std::cout << ", " << arry[i];
    }
    std::cout << std::endl;
}

