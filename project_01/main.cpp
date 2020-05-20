#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "queens.h"

int main() {
    int n;
    std::cin >> n;
    queenBoard q(n);
    std::cout << q.count() << std::endl;

    return 0;
}
