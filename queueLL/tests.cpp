#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <stdexcept>
#include <string>
#include "doctest.h"
#include "QueueLL.h"

QueueLL ql = QueueLL();

TEST_CASE("enqueue + [] operator") {
    CHECK(ql.is_empty());
    
    // CHECK ERROR CATCHING: DEQUEUE EMPTY QUEUE
    bool errCaught = false;
    try {
        ql.dequeue();
    } 
    catch (const std::out_of_range& err) {
        errCaught = true;
    }
    CHECK(errCaught);
    
    // CHECK ERROR CATCHING: ACCESS EMPTY QUEUE
    errCaught = false;
    try {
        ql[1000];
    } 
    catch (const std::out_of_range& err) {
        errCaught = true;
    }
    CHECK(errCaught);
    
    for (int i = 0; i < 11; i++) {
        ql.enqueue(i);
        CHECK(ql.length() == i + 1);
        CHECK(ql[i] == i);
    }

    // CHECK ERROR CATCHING: ACCESS OUT OF BOUNDS 
    errCaught = false;
    try {
        ql[1000];
    } 
    catch (const std::out_of_range& err) {
        errCaught = true;
    }
    CHECK(errCaught);
    
    std::cout << ql.getDebugString() << "\t" << ql.length() << "\n" << std::endl;
}

TEST_CASE("dequeue") {
    for (int i = 0; i < 6; i++) {
        CHECK(ql[0] == i);
        CHECK(ql.dequeue() == i);
    }

    std::cout << ql.getDebugString() << "\t" << ql.length() << "\n" << std::endl;
}

TEST_CASE("is_empty") {
    for (int i = 6; i < 11; i++) {
        CHECK(ql[0] == i);
        CHECK(ql.dequeue() == i);
    }

    CHECK(ql.is_empty());
    
    // CHECK ERROR CATCHING: DEQUEUE EMPTY QUEUE
    bool errCaught = false;
    try {
        ql.dequeue();
    } 
    catch (const std::out_of_range& err) {
        errCaught = true;
    }
    CHECK(errCaught);
}
