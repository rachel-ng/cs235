#include <iostream>
#include <stdexcept>
#include "Node.h"
#include "QueueLL.h"

int main() {
    QueueLL q = QueueLL();

    for (int i = 0; i < 11; i++) {
        q.enqueue(i);
    }

    std::cout << q.getDebugString() << "\t" << q.length() << "\n" << std::endl;

    for (int i = 0; i < 6; i++) {
        std::cout << "q.dequeue():\t" << q[0] << " --> " << q.dequeue() << std::endl;
        std::cout << q.getDebugString() << "\t" << q.length() << "\n" << std::endl;
    }

    std::cout << q.getDebugString() << "\t" << q.length() << std::endl;
    
    return 0;
}

