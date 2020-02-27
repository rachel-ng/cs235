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
    void pushback(std::string s);
    void remove(int index);
    std::string &operator[] (int index);
    std::string getDebugString();
    std::string getDebugStringBack();
    int length();
};
