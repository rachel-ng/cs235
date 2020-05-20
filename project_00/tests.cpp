#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "myVector.h"


myVector<int> p;

TEST_CASE("push"){
    for (int i = 0; i < 99; i++) {
        p.push(i);
        CHECK(p[i] == i);
    }
} 

TEST_CASE("operator []"){
    for (int i = 0; i < 99; i++) {
        CHECK(p[i] == i);
    }
} 

TEST_CASE("pop"){
    int ps;
    for (int i = 0; i < 5; i++) {
        ps = p.size();
        p.pop();
        CHECK(ps == p.size() + 1);
    }
} 

TEST_CASE("capacity"){
    CHECK(p.get_capacity() == 100);
    for (int i = 0; i < 15; i++) {
        p.push(i);
        CHECK(p[i + 94] == i);
    }
    CHECK(p.get_capacity() == 200);
} 

TEST_CASE("size"){
    myVector<int> s;
    CHECK(s.size() == 0);
    s.push(10);
    CHECK(s.size() == 1);
} 
