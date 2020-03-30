#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <stdexcept>
#include <string>
#include "doctest.h"
#include "Queue.h"

Queue q = Queue();

TEST_CASE("enqueue + [] operator") {
    CHECK(q.is_empty());
    
    // CHECK ERROR CATCHING: DEQUEUE EMPTY QUEUE
    bool errCaught = false;
    try {
        q.dequeue();
    } 
    catch (const std::out_of_range& err) {
        errCaught = true;
    }
    CHECK(errCaught);
    
    // CHECK ERROR CATCHING: ACCESS EMPTY QUEUE
    errCaught = false;
    try {
        q[1000];
    } 
    catch (const std::out_of_range& err) {
        errCaught = true;
    }
    CHECK(errCaught);
   
    q.enqueue(10);
    CHECK(q[0] == 10);
    CHECK(10 == q.dequeue());

    for (int i = 0; i < 11; i++) {
        q.enqueue(i);
        CHECK(q.length() == i + 1);
        CHECK(q[i] == i);
    }

    // CHECK ERROR CATCHING: ACCESS OUT OF BOUNDS 
    errCaught = false;
    try {
        q[1000];
    } 
    catch (const std::out_of_range& err) {
        errCaught = true;
    }
    CHECK(errCaught);
    
    std::cout << q.getDebugString() << "\t" << q.length() << "\n" << std::endl;
}

TEST_CASE("dequeue") {
    for (int i = 0; i < 6; i++) {
        CHECK(q[0] == i);
        CHECK(q.dequeue() == i);
    }

    std::cout << q.getDebugString() << "\t" << q.length() << "\n" << std::endl;
}

TEST_CASE("is_empty") {
    for (int i = 6; i < 11; i++) {
        CHECK(q[0] == i);
        std::cout << q.getDebugString() << std::endl;
        std::cout << q.getFullString() << std::endl;
        CHECK(q.dequeue() == i);
    }

    CHECK(q.is_empty());
    
    // CHECK ERROR CATCHING: DEQUEUE EMPTY QUEUE
    bool errCaught = false;
    try {
        q.dequeue();
    } 
    catch (const std::out_of_range& err) {
        errCaught = true;
    }
    CHECK(errCaught);
}
