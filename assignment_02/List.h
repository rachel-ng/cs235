#pragma once

#include <string>
#include "Node.h"

class List{
private:
    Node *head;
    Node *current;
    Node *tail;
    int len;
public:
    List();
    ~List();
    void insert(std::string data);
    void remove(int index);
    void pushback(std::string s);
    std::string &operator[] (int index);
    std::string getDebugString();
    int length();
};
