#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <stdexcept>
#include <string>
#include "doctest.h"
#include "QueueA.h"

QueueA qa = QueueA();

TEST_CASE("QueueA: enqueue + [] operator") {
    CHECK(qa.is_empty());
    
    // CHECK ERROR CATCHING: DEQUEUE EMPTY QUEUE
    bool errCaught = false;
    try {
        qa.dequeue();
    } 
    catch (const std::out_of_range& err) {
        errCaught = true;
    }
    CHECK(errCaught);
    
    // CHECK ERROR CATCHING: ACCESS EMPTY QUEUE
    errCaught = false;
    try {
        qa[1000];
    } 
    catch (const std::out_of_range& err) {
        errCaught = true;
    }
    CHECK(errCaught);
   
    qa.enqueue(10);
    
    std::cout << qa.getFullString() << std::endl;
    std::cout << qa.getDebugString() << "\n" << std::endl;
    
    CHECK(qa[0] == 10);
    CHECK(10 == qa.dequeue());
    
    std::cout << qa.getDebugString() << "\n" << std::endl;

    for (int i = 0; i < 13; i++) {
        qa.enqueue(i);
        CHECK(qa.length() == i + 1);
        CHECK(qa[i] == i);
    }

    // CHECK ERROR CATCHING: ACCESS OUT OF BOUNDS 
    errCaught = false;
    try {
        qa[1000];
    } 
    catch (const std::out_of_range& err) {
        errCaught = true;
    }
    CHECK(errCaught);
    
    std::cout << qa.getFullString() << std::endl;
    std::cout << qa.getDebugString() << "\n" << std::endl;
}

TEST_CASE("dequeue") {
    for (int i = 0; i < 6; i++) {
        CHECK(qa[0] == i);
        CHECK(qa.dequeue() == i);
    }

    std::cout << qa.getFullString() << std::endl;
    std::cout << qa.getDebugString() << "\n" << std::endl;
}

TEST_CASE("is_empty") {
    for (int i = 6; i < 13; i++) {
        CHECK(qa[0] == i);
        CHECK(qa.dequeue() == i);
    }

    CHECK(qa.is_empty());
    
    // CHECK ERROR CATCHING: DEQUEUE EMPTY QUEUE
    bool errCaught = false;
    try {
        qa.dequeue();
    } 
    catch (const std::out_of_range& err) {
        errCaught = true;
    }
    CHECK(errCaught);
   

    // CHECK ARRAY RESIZE
    std::cout << qa.getFullString() << std::endl;
    std::cout << qa.getDebugString() << "\n"  << std::endl;
    
    for (int i = 11; i < 35; i++) {
        qa.enqueue(i);
    }
    std::cout << qa.getFullString() << std::endl;
    std::cout << qa.getDebugString() << std::endl;
}
