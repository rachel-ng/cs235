#include <iostream>
#include <vector>
#include "Node.h"
#include "BSTree.h"

BSTree::BSTree(){
  root = nullptr;
}

void BSTree::insert(int d){
  
}

std::string BSTree::get_debug_string(){

  if (root == nullptr){
    return "";
  } else {
    return  std::to_string( root->getData()) + std::to_string(root->getRight()->getData());
  }
}

void BSTree::setup(){
  Node *n = new Node(10);
  root = n;
  n = new Node(20);
  root->setLeft(n);
  n = new Node(30);
  root->setRight(n);
  n = new Node(40);
  root->getLeft()->setLeft(n);
}

// VIDEO 5
std::string BSTree::get_debug_string_r (){
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
        s += "\n" + debug_string_r(n->getLeft(), l+1); 
        s += "\n" + debug_string_r(n->getRight(), l+1); 
    }
    return s; 
}

