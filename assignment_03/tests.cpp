#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <stdexcept>
#include <string>
#include "doctest.h"
#include "Stack.h"

Stack s;

TEST_CASE("push") {
    bool errCaught = false;
    
    try {
        s.top();
    } 
    catch (const std::out_of_range& err) {
        errCaught = true;
    }
    
    CHECK(errCaught);


    for (int i = 1; i < 6; i++) {
        s.push(i);
        CHECK(s.top() == i);
    }
}

TEST_CASE("top") {
    CHECK(s.top() == 5);

    for (int i = 6; i < 11; i++) {
        s.push(i);
        CHECK(s.top() == i);
    }
}

TEST_CASE("pop") {
    for (int i = 10; i > 0; i--) {
        CHECK(s.pop() == i);
    }
    
    bool errCaught = false;
    
    try {
        s.pop();
    }
    catch (const std::out_of_range& err) {
        errCaught = true;
    }
    
    CHECK(errCaught);
}

TEST_CASE("is_empty") {
    CHECK(s.is_empty());
    s.push(0);
    CHECK(!s.is_empty());
}

TEST_CASE("initialize") {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    s.initialize(vec);
    for (int i = 7; i > -1; i--) {
        CHECK(s.pop() == i);
    }
}

TEST_CASE("get_vector") {
    CHECK(s.get_vector().size() == 0);
    
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    s.initialize(vec);
    
    CHECK(s.get_vector() == vec);

    s.push(7);
    vec.push_back(7);
    CHECK(s.get_vector() == vec);
}

TEST_CASE("swap") {
    s.swap();
    CHECK(s.pop() == 6);
    CHECK(s.pop() == 7);
    
    s.swap();
    CHECK(s.pop() == 4);
    CHECK(s.pop() == 5);
    
    while (!s.is_empty()) {
        s.pop();
    }
    
    bool errCaught = false;
    try {
        s.swap();
    } 
    catch (const std::out_of_range& err) {
        errCaught = true;
    }
    CHECK(errCaught);
}

