#include <stdexcept>
#include <vector>
#include "Stack.h"
#include "List.h"

Stack::Stack(){
    l = new List();
}

void Stack::push(int data){
    l->insert(data);
}

int Stack::pop () {
    if (l->length() == 0) {
        throw std::out_of_range("EMPTY STACK: Can not pop");
    }
    int data = (*l)[0];
    l->remove(0);
    return data;
}

int Stack::top () {
    if (l->length() == 0) {
        throw std::out_of_range("EMPTY STACK: No top");
    }
    return (*l)[0]; 
}

bool Stack::is_empty() {
    return l->length() == 0;
}

std::vector<int> Stack::get_vector() {
    int len = l->length();
    std::vector<int> v;
    v.resize(len);
    for (int i = len - 1; i > -1; i--) {
        v[i] = this->pop();
    }
    return this->initialize(v); 
}

std::vector<int> Stack::initialize(std::vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        this->push(a[i]);
    }
    return a;
}

void Stack::swap() {
    if (l->length() < 2) {
        throw std::out_of_range("Stack contains less than 2 nodes. Can not swap.");
    }
    int uno = this->pop();
    int dos = this->pop();
    
    this->push(uno);
    this->push(dos);
}

std::string Stack::peek() {
    return l->getDebugString();
}

