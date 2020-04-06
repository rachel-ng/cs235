#pragma once
#include <stdexcept>

class QueueA{
private:
    int *list;
    int capacity;
    int front; 
    int back;
public: 
    QueueA();
    void enqueue(int data);
    int dequeue();
    bool is_empty();
    int &operator[] (int index);
    std::string getFullString();
    std::string getDebugString();
    int length();
};
