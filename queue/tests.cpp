#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <stdexcept>
#include <string>
#include "doctest.h"
#include "QueueA.h"
#include "QueueLL.h"

QueueA qa = QueueA();
QueueLL ql = QueueLL();


TEST_CASE("QueueA: enqueue + [] operator") {
    std::cout << "queueA CASES\n\nenqueue + [] operator\n" << std::endl;

    CHECK(qa.is_empty());
    std::cout << qa.getFullString(true, false, true) << std::endl;
    std::cout << qa.getDebugString(false, true, true) << "\n" << std::endl;
    
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


    // VALIDATE ENQUEUE + DEQUEUE
    qa.enqueue(10);
    std::cout << qa.getFullString(true, false, true) << std::endl;
    std::cout << qa.getDebugString(false, true, true) << "\n" << std::endl;
    CHECK(qa[0] == 10);
    CHECK(10 == qa.dequeue());
    
    CHECK(qa.is_empty());
    std::cout << qa.getFullString(true, false, true) << std::endl;
    std::cout << qa.getDebugString(false, true, true) << "\n" << std::endl;


    // ENQUEUE CASES
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
    
    std::cout << qa.getFullString(true, false, false) << std::endl;
    std::cout << qa.getDebugString(false, true, false) << "\n" << std::endl;
}

TEST_CASE("QueueA: dequeue") {
    std::cout << "\ndequeue\n" << std::endl;
    
    std::cout << qa.getFullString(true, false, false) << std::endl;
    std::cout << qa.getDebugString(false, true, true) << "\n" << std::endl;
    
    for (int i = 0; i < 6; i++) {
        CHECK(qa[0] == i);
        CHECK(qa.dequeue() == i);
        CHECK(qa[0] == i + 1);
    }

    std::cout << qa.getFullString(true, false, false) << std::endl;
    std::cout << qa.getDebugString(false, true, true) << "\n" << std::endl;
}

TEST_CASE("QueueA: is_empty") {
    std::cout << "\nis_empty\n" << std::endl;
    
    CHECK(!qa.is_empty());
    
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
    
    std::cout << qa.getFullString(true, true, false) << std::endl;
    std::cout << qa.getDebugString(false, true, true) << "\n"  << std::endl;
}

TEST_CASE("QueueA: resize") {
    std::cout << "\nresize\n" << std::endl;
    
    // CHECK ARRAY RESIZE
    std::cout << qa.getFullString() << std::endl;
    std::cout << qa.getDebugString() << "\n"  << std::endl;
   
    for (int i = 0; i < 12; i++) {
        qa.enqueue(0);
    }

    for (int i = 0; i < 6; i++) {
        qa.enqueue(i);
    }
    
    std::cout << qa.getFullString(true, true, false) << std::endl;
    std::cout << qa.getDebugString(false, true, true) << "\n" << std::endl;
   
    std::cout << "dequeue " << qa.dequeue() << "\t" << qa.getFullString(false, true, true) << "\n\t" << qa.getDebugString(false, true, true) << "\n" << std::endl;
   
    qa.enqueue(6);
    std::cout << "enqueue 6"  << "\t"<< qa.getFullString(false, true, true) << "\n\t" << qa.getDebugString(false, true, true) << "\n" << std::endl;


    // CHECK ERROR CATCHING: ACCESS OUT OF BOUNDS 
    bool errCaught = false;
    try {
        qa[20];
    } 
    catch (const std::out_of_range& err) {
        errCaught = true;
    }
    CHECK(errCaught);


    for (int i = 0; i < 12; i++) {
        qa.dequeue();
    }
    std::cout << "dequeue 12x" << "\t" << qa.getFullString(false, true, true) << "\n\t" << qa.getDebugString(false, true, true) << "\n" << std::endl;
    
    for (int i = 7; i < 24; i++) {
        qa.enqueue(i);
        if (i > 8 && i < 11) {
            std::cout << "enqueue " << i << std::endl;
            std::cout << qa.getFullString(false, true, true) << std::endl;
            std::cout << qa.getDebugString(false, true, true) << "\n" << std::endl;
        }
        if (i > 18 && i < 21) {
            std::cout << "enqueue " << i << std::endl;
            std::cout << qa.getFullString(false, true, true) << std::endl;
            std::cout << qa.getDebugString(false, true, true) << "\n" << std::endl;
        }
    }

}




TEST_CASE("QueueLL: enqueue + [] operator") {
    std::cout << "\n\n\nqueueLL CASES\n\nenqueue + [] operator\n" << std::endl;

    CHECK(ql.is_empty());
    
    std::cout << ql.getDebugString() << "\t" << ql.length() << "\n" << std::endl;
    
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


    // ENQUEUE CASES
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

TEST_CASE("QueueLL: dequeue") {
    std::cout << "\ndequeue\n" << std::endl;
    std::cout << ql.getDebugString() << "\t" << ql.length() << "\n" << std::endl;

    for (int i = 0; i < 6; i++) {
        CHECK(ql[0] == i);
        CHECK(ql.dequeue() == i);
        CHECK(ql[0] == i + 1);
    }

    std::cout << ql.getDebugString() << "\t" << ql.length() << "\n" << std::endl;
}

TEST_CASE("QueueLL: is_empty") {
    std::cout << "\nis_empty\n" << std::endl;
    
    std::cout << ql.getDebugString() << "\t" << ql.length() << "\n" << std::endl;
    
    CHECK(!ql.is_empty());

    for (int i = 6; i < 10; i++) {
        CHECK(ql[0] == i);
        CHECK(ql.dequeue() == i);
        CHECK(ql[0] == i + 1);
    }

    CHECK(ql[0] == 10);
    CHECK(ql.dequeue() == 10);
    
    std::cout << ql.getDebugString() << "\t" << ql.length() << "\n" << std::endl;
    
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

