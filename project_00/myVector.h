#pragma once 

template <typename T>
class myVector{
public: 
    myVector ();
    myVector (int c);
    void push (T data);
    void push (int index, T data);
    T get (int index);
    T & operator[] (int index);
    void pop ();
    void clear (); 
    int get_capacity ();
    int size ();
    void print ();

private: 
    int capacity;
    int curr;
    T *arr;
};

#include "myVector.hxx"
