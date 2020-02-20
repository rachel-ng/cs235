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
    void insert(std::string data);
    void remove(int index);
    std::string &operator[] (int index);
    std::string getDebugString();
    int length();
};
