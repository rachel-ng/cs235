#include <iostream>
#include <stdexcept>
#include <string>
#include "List.h"
#include "Node.h"

List::List(){
  head = nullptr;
  tail = nullptr;
  current = nullptr;
  len=0;
}

List::~List(){
    std::cout << "In the destructor\n";
    Node *t;
    while (head != nullptr){
        t = head;
        head=head->getNext();
        delete t;
    }
}

void List::insert(std::string data){
    Node *t = new Node(data);
    t->setNext(head);
    head->setPrev(t);
    head = t;
    if (len == 0) {
        tail = t;
    }
    len++;
}

void List::pushback(std::string s) {
    if (len < 1) {
        insert(s);
        return;
    }
    Node *t = new Node(s);
    
    tail->setNext(t);
    t->setPrev(tail);
    tail = t;
    
    len++;
}

void List::remove(int index){
    if (index > len || index < 0) {
        return;
    }
    int i = 0;
    Node *prev;
    prev = head;
    while(prev != nullptr && i < index - 1) { 
        prev = prev->getNext();
        i++; 
    }
    Node *next = (prev->getNext())->getNext();
    prev->setNext(next);
    next->setPrev(prev);

    if (index == len - 1) {
        tail = prev;
    }

    len--;
}

std::string &List::operator[] (int index){
    if (index > len - 1 || index < 0) {
        throw std::out_of_range("Index out of range");
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

std::string List::getDebugString(){
    Node *t;
    t = head;
    std::string result="";
    while (t != nullptr){
        result = result + t->getData() + "-->";
        t = t->getNext();
    }
    result = result + "null" + "\ntail: " + tail->getData();;
    return result;
}

int List::length(){
    return len;
}
