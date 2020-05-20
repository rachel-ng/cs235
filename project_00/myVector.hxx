#include "myVector.h"

template <typename T>
myVector<T>::myVector () {
    capacity = 100;
    curr = 0;
    arr = new T[capacity];
}

template <typename T>
myVector<T>::myVector (int c) {
    capacity = c;
    curr = 0;
    arr = new T[capacity];
}

template <typename T>
void myVector<T>::push (T data) {
    if (curr == capacity - 1) {
        T *temp = new T[capacity * 2];

        for (int i = 0; i < capacity; i++) {
            temp[i] = arr[i];
        }
        
        delete[] arr;
        capacity *= 2;
        arr = temp;
        arr[curr] = data;
        curr++;
    } 
    else {
        arr[curr] = data;
        curr++;
    }
}

template <typename T>
void myVector<T>::push (int index, T data) {
    if (index == capacity - 1) {
        push(data);
    } 
    else {
        arr[index] = data;
    }
}

template <typename T>
T myVector<T>::get (int index) {
    if (index < curr) {
        arr[index];
    }
}

template <typename T>
T & myVector<T>::operator[] (int index){
    return arr[index];
}

template <typename T>
void myVector<T>::pop () {
    curr--;
}

template <typename T>
void myVector<T>::clear () {
    arr = new T[capacity];
}

template <typename T>
int myVector<T>::get_capacity () {
    return capacity;
}

template <typename T>
int myVector<T>::size () {
    return curr;
}

template <typename T>
void myVector<T>::print () {
    for (int i = 0; i < curr - 1; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[curr-1] << std::endl;
}
