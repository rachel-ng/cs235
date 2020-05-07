#pragma once
#include <stdexcept>

void prnt (int arry[], int size);
void prnt_i (int arry[], int size);

void heapify (int arry[], int size);
void siftup (int arry[], int n, int size);
int removemin (int arry[], int size);
void heapsort (int arry[], int size);
