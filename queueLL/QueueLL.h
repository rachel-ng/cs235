#pragma once
#include <stdexcept>
#include <string>
#include "Node.h"

class QueueLL{
private:
    Node *head;
    Node *tail;
    int len;
public: 
    QueueLL();
    ~QueueLL();
    void enqueue(int data);
    int dequeue();
    bool is_empty();
    int &operator[] (int index);
    std::string getDebugString();
    int length();
};
