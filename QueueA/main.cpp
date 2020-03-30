#include <iostream>
#include <stdexcept>
#include "Queue.h"

int main() {
    Queue q = Queue();

    std::cout << q.getFullString() << std::endl;
    
    for (int i = 0; i < 11; i++) {
        q.enqueue(i);
    }
    
    std::cout << q.getDebugString() << "\t" << q.length() << "\n" << std::endl;
    std::cout << q.getFullString() << std::endl;

    std::cout << "\n\ndequeue" << std::endl;

    for (int i = 0; i < 6; i++) {
        //std::cout << "q.dequeue():\t" << q.dequeue() << std::endl;
        std::cout << "q.dequeue():\t" << q[0] << " --> " << q.dequeue() << std::endl;
        std::cout << q.getDebugString() << "\t" << q.length() << "\n" << std::endl;
    }

    std::cout << "\n" << q.getDebugString() << "\t" << q.length() << std::endl;
    std::cout << q.getFullString() << std::endl;
    
    return 0;
}

