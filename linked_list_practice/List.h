#pragma once

#include <string>
#include "Node.h"

class List{
private:
    Node *head;
    Node *tail;
    int len;
public:
    List();
    ~List();
    void insert(int data);
    void remove(int index);
    void pushback(int s);
    int &operator[] (int index);
    std::string getDebugString();
    int length();
};
