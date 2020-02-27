#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include "List.h"
#include "Node.h"

List::List(){
  head = nullptr;
  current = nullptr;
  tail = nullptr;
  len=0;
}

List::~List(){
    //std::cout << "In the destructor\n";
    Node *t;
    if (len == 0) {
        delete head;
        delete tail;
        return;
    }
    while (head != tail){
        t = head;
        head=head->getNext();
        delete t;
    }
    delete tail;
}
void List::insert(std::string data){
    Node *t = new Node(data);
    
    t->setNext(head);
    
    if (head != nullptr) {
        head->setPrev(t);
    }
    
    head = t;
    
    if (len == 0) {
        tail = t;
    }
   
    current = t;
    curr = 0;

    len++;
}

void List::pushback(std::string s) {
    if (len == 0) { // just insert it if no nodes
        insert(s);
        return;
    }
    
    Node *n = new Node(s);
    
    tail->setNext(n);
    n->setPrev(tail);
    
    tail = n;
    
    current = n;
    curr = len;

    len++;
}

void List::remove(int index){
    if (index > len - 1 || index < 0) {
        return;
    }
    
    if (index == 0) { // if removing head 
        if (len == 1) {  // if only node
            delete head;
            delete tail;
            head = nullptr;
            tail = nullptr;
            current = nullptr;
            curr = -1;
        }
        else {
            Node *next = head->getNext();
            next->setPrev(nullptr);
            delete head;
            head = next;
            current = head;
            curr = 0;
        }
        len--;
        return;
    }
    
    if (index == len - 1) { // if removing tail 
        Node *prev = tail->getPrev();
        prev->setNext(nullptr);
        delete tail;
        tail = prev;
        current = tail;
        curr = index - 1;
        len--;
        return;
    }

    if (index == curr) {
        Node *prev = current->getPrev();
        Node *next = current->getNext();
        next->setPrev(prev);
        delete current;
        prev->setNext(next);
        current = prev;
        curr = index - 1;
        len--;
        return;
    }

    int h = index;
    int c = abs(curr - index);
    int b = len - 1 - index;
    int i = h > b ? (b > c ? curr : len - 1) : 0;
    int dec = index > i ? 1 : -1;
    Node *prev = h > b ? (b > c ? current : tail) : head;

    std::cout << "remove " << index << " " << (h > b ? (b > c ? "current" : "tail") : "head") << std::endl;
   
    if (dec == 1) { 
        while(prev != nullptr && i < index) { 
            prev = prev->getNext();
            i+=dec; 
        }
    }
    
    else { 
        while(prev != nullptr && i > index) { 
            prev = prev->getPrev();
            i+=dec; 
        }
    }
    
    Node *next = (prev->getNext())->getNext();
    next->setPrev(prev);
    delete prev->getNext();
    prev->setNext(next);
    
    current = prev;
    curr = index - 1;

    len--;
}

std::string &List::operator[] (int index){
    if (index > len - 1 || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    
    if (index == 0) {
        current = head;
        curr = index;
        return head->data;
    }
    if (index == len - 1) {
        current = tail;
        curr = index;
        return tail->data;
    }
    if (index == curr) {
        return current->data;
    }
    
    int h = index;
    int c = abs(curr - index);
    int b = len - 1 - index;
    int i = h > b ? (b > c ? curr : len - 1) : 0;
    int dec = index > i ? 1 : -1;
    Node *t = h > b ? (b > c ? current : tail) : head;

    if (dec == 1) { 
        while(t != nullptr && i < index) { 
            t = t->getNext();
            i+=dec; 
        }
    }
    
    else { 
        while(t != nullptr && i > index) { 
            t = t->getPrev();
            i+=dec; 
        }
    }

    current = t;
    curr = index;
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
    result = result + "null";
    return result;
}

std::string List::getDebugStringBack(){ 
    // reversed debug string
    // proof of prev link 

    Node *t;
    t = tail;
    std::string result="";
    while (t != nullptr){
        result = result + t->getData() + "<--";
        t = t->getPrev();
    }
    result = result + "null";
    return result;
}

int List::length(){
    return len;
}
