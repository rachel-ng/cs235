#include "funcs.h"
#include "Node.h"

Node *reverse(Node *l) {
    if (l == nullptr) {
        return l;
    }
    return rev(nullptr, l);    
}

Node *rev(Node *p, Node *l) {
    if (l == nullptr) {
        return p;
    }

    Node *n = l->getNext();
    l->setNext(p);
    return rev(l,n);
}

Node *merge(Node *a, Node *b) {
    if (a == nullptr) {
        return b;
    }
    if (b == nullptr) {
        return a;
    }

    Node *head;
    if (a->getData() > b->getData()) {
        head = b;
        b = b->getNext();
    }
    else {
        head = a;
        a = a->getNext();
    }

    Node *curr = head;
    while(a != nullptr && b != nullptr) {
        if (a->getData() > b->getData()) {
            curr->setNext(b);
            curr = curr->getNext();
            b = b->getNext();
        }
        else {
            curr->setNext(a);
            curr = curr->getNext();
            a = a->getNext();
        }
    }
    
    if (a != nullptr) {
        curr->setNext(a);
    }
    if (b != nullptr) {
        curr->setNext(b);
    }

    return head;
}
