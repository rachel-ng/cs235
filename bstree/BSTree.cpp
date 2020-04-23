#include <iostream>
#include <vector>
#include "Node.h"
#include "BSTree.h"

BSTree::BSTree () {
  root = nullptr;
}

bool childless (Node *n) {
    return (n->getLeft() == nullptr && n->getRight() == nullptr);
}

Node* BSTree::minp (Node *start) {
    Node *n = start;
    if (n->getLeft() == nullptr) {
        return n;
    }
    while (n != nullptr && n->getLeft() != nullptr && (n->getLeft())->getLeft() != nullptr) {
        n = n->getLeft();
    }
    return n;
}

void BSTree::insert (int d){
    if (root==nullptr){
        root = new Node(d);
    } 
    else {
        insert(root, d);
    }
}

void BSTree::insert (Node *n, int d) {
    int val = n->getData();
    if (d > val) {
        if (n->getRight() != nullptr) {
            insert(n->getRight(), d);
        } 
        else {
            n->setRight(new Node(d));
        }
    } 
    else {
        if (n->getLeft() != nullptr) {
            insert(n->getLeft(), d);
        } 
        else {
            n->setLeft(new Node(d));
        }
    }
}

void BSTree::remove (int d) {
    Node *p = root;
    Node *n = root;
    
    if (root->getData() == d) {
        if (childless(root)) {
            root = nullptr;
            return;
        }

        Node *l = n->getLeft();
        Node *r = n->getRight();
        n->setChildren(nullptr, nullptr);
        Node *m = minp(r);
        Node *c = m->getLeft() != nullptr ? m->getLeft() : m;
        r = r == c ? r->getRight() : r;
        m->setLeft(nullptr);
        c->setChildren(l,r);
        root = c;
        return;
    }

    while (n != nullptr && !childless(n) && n->getData() != d) {
        p = n;
        n = (n->getData() > d) ? n->getLeft() : n->getRight();
    }
    
    if (n == nullptr || n->getData() != d) {
        return;
    }

    bool left = p->getData() > d ? true : false;
    int children = n->getRight() != nullptr ? (n->getLeft() != nullptr ? 2 : 1) : (n->getLeft() != nullptr ? 1 : 0);
    Node *c = (children == 0) ? nullptr : ((n->getRight() != nullptr) ? n->getRight() : n->getLeft());
    
    if (children == 2) {
        Node *l = n->getLeft();
        Node *r = n->getRight();
        n->setChildren(nullptr, nullptr);
        Node *m = minp(r);
        c = m->getLeft() != nullptr ? m->getLeft() : m;
        r = r == c ? r->getRight() : r;
        m->setLeft(nullptr);
        c->setChildren(l,r);
    }
    
    if (left) {
        p->setLeft(c);
    }
    else {
        p->setRight(c);
    }

    delete n;
    return;
}

void BSTree::setup () {
  Node *n = new Node(10);
  root = n;
  n = new Node(20);
  root->setLeft(n);
  n = new Node(30);
  root->setRight(n);
  n = new Node(40);
  root->getLeft()->setLeft(n);
}

std::string BSTree::get_debug_string () {
  if (root == nullptr){
    return "";
  }
  else {
    return  std::to_string( root->getData()) + std::to_string(root->getRight()->getData());
  }
}

// VIDEO 5
std::string BSTree::get_debug_string_r () {
    return debug_string_r(root, 0);
}

std::string BSTree::debug_string_r (Node *n, int l) {
    std::string s;
    
    for (int i = 0; i < l; i++) {
        s += "\t";
    }
    
    s += "|-- ";

    if (n == nullptr) {
        s += "null";
    }
    else {
        s += std::to_string(n->getData());
        s += "\n" + debug_string_r(n->getRight(), l+1); 
        s += "\n" + debug_string_r(n->getLeft(), l+1); 
    }
    return s; 
}

