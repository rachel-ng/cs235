#include <iostream>
#include "Queue.h"

Queue::Queue() {
    capacity = 10;
    front = -1;
    back = -1;
    list = new int[capacity];
}

void Queue::enqueue(int data) {
    if (front = -1 && back == -1) {
        front = 0;
    }

    if (back == capacity - 1) {
        int  cap = front > 0 ? capacity : capacity * 2;
        int *temp = new int [cap];

        for (int i = 0; i < back - front + 1; i++) {
            temp[i] = list[front + i];
        }

        delete[] list;
        
        list = temp;
        capacity = cap;
        back = back - front;
        front = 0;

        back++;
        list[back] = data;
    }
    else {
        back++;
        list[back] = data;
    }
}

int Queue::dequeue() {
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

bool Queue::is_empty() {
    return front == -1 && back == -1;
}

int &Queue::operator[] (int index){
    if (front == -1 && back == -1) {
        throw std::out_of_range("EMPTY QUEUE: Can not access element");
    }
    if (index < 0 || index + front > back + 1) {
        throw std::out_of_range("OUT OF RANGE: Can not access element");
    }
    return list[index + front];
}

std::string Queue::getFullString(){
    std::string result = "";
    for (int i = 0; i < capacity; i++){
        result = result + std::to_string(list[i]) + "-->";
    }
    result = result + "null\t" + std::to_string(capacity);
    return result;
}

std::string Queue::getDebugString(){
    std::string result = "";//"front: " + std::to_string(front) + "\nback: " + std::to_string(back) + "\n";
    for (int i = front; i < back + 1; i++){
        result = result + std::to_string(list[i]) + "-->";
    }
    result = result + "null\t" + std::to_string(back - front + 1);
    return result;
}

int Queue::length() {
    return back - front + 1;
}

