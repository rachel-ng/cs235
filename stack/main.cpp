#include <iostream>
#include <stdexcept>
#include <vector>
#include "Stack.h"
#include "List.h"
int main() {
    Stack s = Stack();
    
    s.push(1);
    std::cout << s.peek() << std::endl;
    std::cout << "pop: " << s.pop() << std::endl;
    std::cout << s.peek() << std::endl;

    return 0;
}
