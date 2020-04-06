#include <iostream>
#include "List.h"

int main() {
    List *l = new List();

    delete l;
    std::cout << "The end\n";
    return 0;
}

