#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "List.h"

TEST_CASE("insert"){
    List *l = new List();
    for (int i = 0; i < 9; i++) {
        l->insert(std::to_string(i));
        CHECK((*l)[0] == std::to_string(i));
    }
    std::cout << l->getDebugString() << "\n";
    delete l; 
} 

TEST_CASE("pushback"){
    List *l = new List();
    for (int i = 0; i < 9; i++) {
        l->pushback(std::to_string(i));
        CHECK((*l)[i] == std::to_string(i));
    }
    std::cout << l->getDebugString() << "\n";
    delete l; 
} 

TEST_CASE("remove"){
    List *l = new List();
    l->pushback("mots 7 comes out tomorrow!!");
    for (int i = 0; i < 9; i++) {
        l->insert(std::to_string(i));
        l->remove(0);
        CHECK(l->length() == 1);
    }
    std::cout << l->getDebugString() << "\n";
    delete l; 
} 

TEST_CASE("[]"){
    List *l = new List();
    for (int i = 0; i < 9; i++) {
        l->pushback(std::to_string(i));
        CHECK((*l)[i] == std::to_string(i));
    }
    (*l)[5] = "stream black swan";
    CHECK((*l)[5] == "stream black swan");

    std::cout << l->getDebugString() << "\n";
    delete l; 
} 
