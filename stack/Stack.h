#pragma once
#include <stdexcept>
#include <vector>
#include "List.h"

class Stack{
private:
    List *l; 
public:
    Stack();
    void push (int data);
    int pop ();
    int top ();
    bool is_empty();
    std::vector<int> get_vector();
    std::vector<int> initialize(std::vector<int> a);
    void swap();
    std::string peek();
};
