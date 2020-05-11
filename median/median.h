#pragma once
#include <stdexcept>

void prnt (double arry[], int size);
void prnt_i (double arry[], int size);

double median (double arry[], int size);
void minheapify (double arry[], int size);
void minsiftup (double arry[], int n, int size);
int removemin (double arry[], int size);
void minheapsort (double arry[], int size);
void maxheapify (double arry[], int size);
void maxsiftup (double arry[], int n, int size);
int removemax (double arry[], int size);
void maxheapsort (double arry[], int size);
