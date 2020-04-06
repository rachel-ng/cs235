#include <iostream>
#include "QueueA.h"

QueueA::QueueA() {
    capacity = 10;
    front = -1;
    back = -1;
    list = new int[capacity];
}

void QueueA::resize() {
    int  cap = front > 0 ? (capacity / 2 > length() ? capacity / 2 : capacity) : capacity * 2;
    int *temp = new int [cap];
    
    for (int i = 0; i < back - front + 1; i++) {
        temp[i] = list[front + i];
    }

    delete[] list;
    
    //std::cout << "resize " << capacity << " --> " << cap << std::endl;

    list = temp;
    capacity = cap;
    back = back - front;
    front = 0;
}

void QueueA::enqueue(int data) {
    if (front == -1 && back == -1) {
        front = 0;
    }
    
    if (back == capacity - 2) {
        resize();
    }
    
    back++;
    list[back] = data;
}

int QueueA::dequeue() {
    if (front == -1 && back == -1) {
        throw std::out_of_range("EMPTY QUEUE: Nothing to dequeue");
    }
   
    int d = list[front];
    front++;
    
    if (front > back) {
        front = -1;
        back = -1;
    }

    return d; 
}

bool QueueA::is_empty() {
    return front == -1 && back == -1;
}

int &QueueA::operator[] (int index){
    if (front == -1 && back == -1) {
        throw std::out_of_range("EMPTY QUEUE: Can not access element");
    }
    
    if (index < 0 || index + front > back) {
        throw std::out_of_range("OUT OF RANGE: Can not access element");
    }
    
    return list[index + front];
}

std::string QueueA::getFullString(){
    std::string result = "" ;
    
    for (int i = 0; i < capacity; i++){
        result += std::to_string(list[i]) + "-->";
    }
    
    return result + "null";
}

std::string QueueA::getFullString(bool f, bool c, bool compact){
    std::string result = f ? 
                            (compact ? 
                            "f: " + std::to_string(front) + "\tb: " + std::to_string(back) + "\t" : 
                            "front: " + std::to_string(front) + "\tback: " + std::to_string(back) + "\n"
                            )
                            : "";
    
    for (int i = 0; i < capacity; i++){
        result += std::to_string(list[i]) + "-->";
    }
    
    return result + (c ? "null\t" + std::to_string(capacity) : "null");
}

std::string QueueA::getDebugString(){
    if (length() == 0) {
        return "null-->null";
    }

    std::string result = "";
    
    for (int i = front; i < back + 1; i++){
        result += std::to_string(list[i]) + "-->";
    }

    return result + "null";
}

std::string QueueA::getDebugString(bool f, bool l, bool compact){
    std::string result = f ? 
                            (compact ? 
                            "f: " + std::to_string(front) + "\tb: " + std::to_string(back) + "\t" : 
                            "front: " + std::to_string(front) + "\tback: " + std::to_string(back) + "\n"
                            )
                            : "";
    
    if (length() == 0) {
        return result + (l ? "null->null\t" + std::to_string(length()) : "null->null");
    }

    for (int i = front; i < back + 1; i++){
        result += std::to_string(list[i]) + "-->";
    }
    
    return result + (l ? "null\t" + std::to_string(length()) : "null");
}

int QueueA::length() {
    return front == -1 && back == -1 ? 0 : back - front + 1;
}

