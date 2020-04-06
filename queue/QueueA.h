#pragma once
#include <stdexcept>

class QueueA{
private:
    int *list;
    int capacity;
    int front; 
    int back;
    void resize();
public: 
    QueueA();
    void enqueue(int data);
    int dequeue();
    bool is_empty();
    int &operator[] (int index);
    std::string getFullString();
    std::string getFullString(bool f, bool c, bool compact);
    std::string getDebugString();
    std::string getDebugString(bool f, bool l, bool compact);
    int length();
};
