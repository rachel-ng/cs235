#include <iostream>
#include "QueueLL.h"

QueueLL::QueueLL() {
    head = nullptr;
    tail = nullptr;
    len = 0;
}

QueueLL::~QueueLL(){
    std::cout << "In the destructor\n";
    Node *t;
    while (head != nullptr){
        t = head;
        head=head->getNext();
        delete t;
    }
}

void QueueLL::enqueue(int data) {
    Node *t = new Node(data);
    if (len == 0) {
        head = t;
    }
    else {
        tail->setNext(t);
    }
    tail = t;
    len++;
}

int QueueLL::dequeue() {
    if (len == 0) {
        throw std::out_of_range("EMPTY QUEUE: Nothing to dequeue");
    }

    Node *prev = head;
    int n = prev->getData();
    head = head->getNext();
    delete prev;
    len--;
    return n;
}

bool QueueLL::is_empty() {
    return len == 0;
}

int &QueueLL::operator[] (int index){
    if (len == 0) {
        throw std::out_of_range("EMPTY QUEUE: Can not access element");
    }
    if (index < 0 || index > len - 1) {
        throw std::out_of_range("OUT OF RANGE: Can not access element");
    }
    
    if (index == len - 1) {
        return tail->data;
    }
    
    int i = 0;
    Node *t;
    t = head;
    while(t != nullptr && i < index) { 
        t = t->getNext();
        i++; 
    }
    return t->data; 
}

std::string QueueLL::getDebugString(){
    Node *t;
    t = head;
    std::string result="";
    while (t != nullptr){
        result = result + std::to_string(t->getData()) + "-->";
        t = t->getNext();
    }
    result = result + "null";
    return result;
}

int QueueLL::length() {
    return len;
}
