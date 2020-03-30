#include <iostream>
#include <string>
#include "List.h"
#include "Node.h"

List::List(){
  head = nullptr;
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
void List::insert(int data){
    Node *t = new Node(data);
    t->setNext(head);
    head = t;
    len++;
}

void List::remove(int index){
    if (index > len || index < 0) {
        return;
    }
    int i = 0;
    Node *prev;
    prev = head;
    
    if (index == 0) {
        head = head->getNext();
        delete prev;
        len--;
        return;
    }

    while(prev != nullptr && i < index - 1) { 
        prev = prev->getNext();
        i++; 
    }
    prev->setNext((prev->getNext())->getNext());

    len--;
}

void List::pushback(int s) {
    if (len < 1) {
        insert(s);
        return;
    }
    Node *t;
    Node *n = new Node(s);
    t = head;
    while(t->getNext() != nullptr) { 
        t = t->getNext();
    }
    t->setNext(n);
    len++;
}


int &List::operator[] (int index){
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
        result = result + std::to_string(t->getData()) + "-->";
        t = t->getNext();
    }
    result = result + "null";
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
