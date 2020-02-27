#include <iostream>
#include <string>
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
        }
        else {
            Node *next = head->getNext();
            next->setPrev(nullptr);
            delete head;
            head = next;
        }
        len--;
        return;
    }
    
    if (index == len - 1) { // if removing tail 
        Node *prev = tail->getPrev();
        prev->setNext(nullptr);
        delete tail;
        tail = prev;
        len--;
        return;
    }
    
    int i;
    Node *prev;

    if (index <= len / 2) { 
        // if in first half of linked list 
        
        i = 0;
        prev = head;
        while(prev != nullptr && i < index - 1) { 
            prev = prev->getNext();
            i++; 
        }
    }
    else { 
        // if in second half of linked list
        
        i = len - 1;
        prev = tail;
        while(prev != nullptr && i > index - 1) { 
            prev = prev->getPrev();
            i--; 
        }
    }

    Node *next = (prev->getNext())->getNext();
    next->setPrev(prev);
    delete prev->getNext();
    prev->setNext(next);
    len--;
}

std::string &List::operator[] (int index){
    if (index == 0) {
        return head->data;
    }
    if (index == len - 1) {
        return tail->data;
    }
    
    int i;
    Node *t;

    if (index <= len / 2) { 
        // if in first half of linked list
        
        i = 0;
        t = head;
        while(t != nullptr && i < index) { 
            t = t->getNext();
            i++; 
        }
    }
    else { 
        // if in second half of linked list 
        
        i = len - 1;
        t = tail;
        while(t != nullptr && i > index) { 
            t = t->getPrev();
            i--; 
        }
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
