#include <stdexcept>
#include <string>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("reverse") {
    Node a(0);
    Node b(1);
    Node c(2);
    Node d(3);
    Node e(4);
    Node f(5);
    
    a.setNext(&b);
    b.setNext(&c);
    c.setNext(&d);
    d.setNext(&e);
    e.setNext(&f);
    
    reverse(&a);
    
    CHECK(f.getNext() == &e);
    CHECK(e.getNext() == &d);
    CHECK(d.getNext() == &c);
    CHECK(c.getNext() == &b);
    CHECK(b.getNext() == &a);
    CHECK(a.getNext() == nullptr);
}

TEST_CASE("merge") {
    Node a(0);
    Node b(1);
    Node c(2);
    Node d(3);
    Node e(4);
    Node f(5);
    Node g(6);
    Node h(7);
    
    a.setNext(&b);
    b.setNext(&c);
    
    d.setNext(&e);
    e.setNext(&f);
    f.setNext(&g);
    g.setNext(&h);
    
    Node *m = merge(&a, &d);
    
    for (int i = 0; i < 8; i++) {
        CHECK(m->getData() == i);
        std::cout << m->getData() << std::endl;
        m= m->getNext();
    }
}
