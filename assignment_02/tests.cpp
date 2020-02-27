#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "List.h"

TEST_CASE("insert"){
    std::cout << "insert\n" << std::endl;
    List *l = new List();
    for (int i = 0; i < 9; i++) {
        l->insert(std::to_string(i));
        CHECK((*l)[0] == std::to_string(i));
        std::cout << l->getDebugString() << "\n";
    }
    std::cout << l->getDebugString() << "\n" << std::endl;
    delete l; 
} 

TEST_CASE("pushback"){
    std::cout << "\npushback\n" << std::endl;
    List *l = new List();
    for (int i = 0; i < 9; i++) {
        l->pushback(std::to_string(i));
        CHECK((*l)[i] == std::to_string(i));
        std::cout << l->getDebugString() << "\n";
    }
    std::cout << l->getDebugString() << "\n" << std::endl;
    delete l; 
} 

TEST_CASE("remove"){
    std::cout << "\nremove\n" << std::endl;
    List *l = new List();
    l->pushback("on mv comes out tomorrow!!");
    l->pushback("we stan bts");
    l->pushback("mots 7 comes out tomorrow!!");
    l->pushback("we stan bts");
    l->pushback("we stan bts");
    l->pushback("we stan bts");
    l->pushback("delete meh");
    l->pushback("we stan bts");
    std::cout << l->getDebugString() << "\n" << std::endl;
    std::cout << "removing 2: " << (*l)[2] << std::endl;
    l->remove(2);
    std::cout << l->getDebugString() << "\n" << std::endl;
    std::cout << "removing 5: " << (*l)[5] << std::endl;
    l->remove(5);
    std::cout << "removing " << (l->length()-1) << ": " << (*l)[l->length() - 1] << std::endl;
    l->remove(l->length()-1);
    std::cout << "removing " << (l->length()-1) << ": " << (*l)[l->length() - 1] << std::endl;
    l->remove(l->length()-1);
    std::cout << "removing " << (l->length()-1) << ": " << (*l)[l->length() - 1] << std::endl;
    l->remove(l->length()-1);
    std::cout << "removing " << (l->length()-1) << ": " << (*l)[l->length() - 1] << std::endl;
    l->remove(l->length()-1);
    int len = l->length();
    std::cout << "\n" << l->getDebugString() << "\n" << std::endl;
    for (int i = 0; i < 9; i++) {
        l->insert(std::to_string(i));
        std::cout << l->getDebugString() << "\n";
        std::cout << "removing 0: " << (*l)[0] << std::endl;
        l->remove(0);
        std::cout << l->getDebugString() << "\n" << std::endl;
        CHECK(l->length() == len);
    }
    std::cout << l->getDebugString() << "\n";
    std::cout << "removing 0: " << (*l)[0] << std::endl;
    l->remove(0);
    std::cout << l->getDebugString() << "\n" << std::endl;
    delete l; 
} 

TEST_CASE("[] overload"){
    std::cout << "\n[] overload\n" << std::endl;
    List *l = new List();
    std::cout << l->getDebugString() << "\n";
    for (int i = 0; i < 9; i++) {
        l->pushback(std::to_string(i));
        CHECK((*l)[i] == std::to_string(i));
    }
    (*l)[5] = "stream black swan";
    CHECK((*l)[5] == "stream black swan");

    (*l)[7] = "stream on";
    CHECK((*l)[7] == "stream on");

    std::cout << l->getDebugString() << "\n" << std::endl;
    std::cout << l->getDebugStringBack() << "\n" << std::endl;
    delete l; 
} 
