#include <iostream>
#include <stdexcept>
#include <vector>
#include "Stack.h"
#include "List.h"
int main() {
    Stack s = Stack();
    
    s.push(1);
    std::cout << s.pop() << std::endl;

    return 0;
}
