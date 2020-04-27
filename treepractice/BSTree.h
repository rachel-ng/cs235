#pragma once
#include <stdio.h>
#include <vector>

class BSTree{
 private:
  Node *root;
  Node *minp (Node *start);
  std::string debug_string_r (Node *n, int l);

 public:
  BSTree ();
  void insert (int d);
  void insert (Node *n, int d);
  void remove (int d);
  std::string get_debug_string ();
  std::string get_debug_string_r ();
  void setup ();
  int countNodes ();
  int nnodes (Node* n);
  int sumNodes ();
  int snodes (Node* n);
  int countLeaves ();
  int leaves (Node* n);
  int height ();
  int tall (Node* n);
};

bool childless (Node *n);

