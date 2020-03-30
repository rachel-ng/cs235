#pragma once
#include <stdexcept>

class Queue{
private:
    int *list;
    int capacity;
    int front; 
    int back;
public: 
    Queue();
    void enqueue(int data);
    int dequeue();
    bool is_empty();
    int &operator[] (int index);
    std::string getFullString();
    std::string getDebugString();
    int length();
};
