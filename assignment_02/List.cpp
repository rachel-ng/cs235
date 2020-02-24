#include <iostream>
#include <stdexcept>
#include <string>
#include "List.h"
#include "Node.h"

List::List(){
  head = nullptr;
  tail = nullptr;
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
    head = t;
    if (len == 0) {
        tail = t;
    }
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
    prev->setNext((prev->getNext())->getNext());
    if (index == len - 1) {
        tail = prev;
    }

    len--;
}

void List::pushback(std::string s) {
    if (len < 1) {
        insert(s);
        return;
    }
    //Node *t;
    Node *n = new Node(s);
    t = head;
    while(t->getNext() != nullptr) { 
        t = t->getNext();
    }
    t->setNext(n);
    
    // tail->setNext(n);
    // tail = n;
    
    len++;
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
    /*Node *t = head;
    int l = 0;
    while (t!=nullptr){
        t=t->getNext();
        l++;
    }
    return l;*/
    return len;
}
