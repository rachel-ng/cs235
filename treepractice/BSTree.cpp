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
    
    if (root == nullptr || childless(root)) {
        root = nullptr;
        return;
    }
    
    if (root->getData() == d) {
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

    Node *l = n->getLeft();
    Node *r = n->getRight();
    int children = r != nullptr ? (l != nullptr ? 2 : 1) : (l != nullptr ? 1 : 0);
    Node *c = (children == 0) ? nullptr : ((r != nullptr) ? r : l);
    
    if (children == 2) {
        n->setChildren(nullptr, nullptr);
        Node *m = minp(r);
        c = m->getLeft() != nullptr ? m->getLeft() : m;
        r = r == c ? r->getRight() : r;
        m->setLeft(nullptr);
        c->setChildren(l,r);
    }
    
    if (p->getData() > d) {
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


// CHALLENGE 1: COUNT NODES
int BSTree::countNodes (){
    return nnodes (root);
}

int BSTree::nnodes (Node* n) {
    if (n == nullptr) {
        return 0;
    }
    return 1 + nnodes(n->getLeft()) + nnodes(n->getRight());
}


// CHALLENGE 2: SUM NODES
int BSTree::sumNodes (){
    return snodes (root);
}

int BSTree::snodes (Node* n) {
    if (n == nullptr) {
        return 0;
    }
    return n->getData() + snodes(n->getLeft()) + snodes(n->getRight());
}


// CHALLENGE 3: COUNT LEAVES
int BSTree::countLeaves (){
    return leaves (root);
}

int BSTree::leaves (Node* n) {
    if (n == nullptr) {
        return 0;
    }
    if (n->getLeft() == nullptr && n->getRight() == nullptr) {
        return 1;
    }
    return 0 + leaves(n->getLeft()) + leaves(n->getRight());;
}


// CHALLENGE 4: HEIGHT
int BSTree::height (){
    return tall (root);
}

int BSTree::tall (Node* n) {
    if (n == nullptr) {
        return 0;
    }
    int l = tall(n->getLeft());
    int r = tall(n->getRight());
    return 1 + (l > r ? l : r);
}


// CHALLENGE 5: SUM AT LEVEL 
int BSTree::sumLevel (int height){
    return sumLvl(root, height);
}

int BSTree::sumLvl (Node* n, int height){
    if (n == nullptr) {
        return 0;
    }
    if (height == 0) {
        return n->getData();
    }
    return sumLvl(n->getLeft(), height - 1) + sumLvl(n->getRight(), height - 1);
}

