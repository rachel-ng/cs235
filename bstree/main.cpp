#include <iostream>
#include "Node.h"
#include "BSTree.h"
int main()
{
  // VIDEO 2
  Node *a = new Node(20);
  Node *b = new Node(30);
  Node *c = new Node(40);
  Node *d = new Node(50);
  Node *e = new Node(60);
  Node *f = new Node(70);
  Node *g = new Node(80);
  Node *h = new Node(90);
  Node *i = new Node(100);
  a->setLeft(b);
  a->setRight(c);
  b->setLeft(d);
  c->setLeft(e);
  c->setRight(f);
  e->setLeft(g);
  e->setRight(h);
  h->setRight(i);

  /*
  std::cout << a->getData() << "\n";
  std::cout << "\t" << a->getLeft()->getData() << "\t" << a->getRight()->getData() << "\n" << std::endl;
  
  std::cout << "\t" << b->getData() << "\n";
  std::cout << "\t" << b->getLeft()->getData() << "\n" << std::endl;
  
  std::cout << "\t" << c->getData() << "\n";
  std::cout << "\t" << c->getLeft()->getData() << "\t" << c->getRight()->getData() << "\n" << std::endl;
  
  std::cout << "\t\t" << e->getData() << "\n";
  std::cout << "\t\t" << e->getLeft()->getData() << "\t" << e->getRight()->getData() << "\n" << std::endl;
  
  std::cout << "\t\t\t" << h->getData() << "\n";
  std::cout << "\t\t\t" << h->getRight()->getData() << "\n";
  */

  std::cout << a->getData() << std::endl;
  std::cout << a->getLeft()->getData() << "\t" << a->getRight()->getData() << std::endl;
  std::cout << a->getLeft()->getLeft()->getData() << "\t" << a->getRight()->getLeft()->getData() << "\t" << a->getRight()->getRight()->getData() << std::endl;
  std::cout <<  "\t" << a->getRight()->getLeft()->getLeft()->getData() << "\t" << a->getRight()->getLeft()->getRight()->getData() << "\t" << std::endl;
  std::cout <<  "\t" << a->getRight()->getLeft()->getRight()->getRight()->getData() << std::endl;

  // VIDEO 5
  BSTree *t = new BSTree();
  t->setup();
  std::cout << t->get_debug_string_r() << "\n\n" << std::endl;



  delete t;

  t = new BSTree();
  int arr[11] = {10, 20, 27, 5, 4, 22, 35, 42, 8, 3, 7};
  for (int i = 0; i < 11; i++) {
    t->insert(arr[i]);
  }
  
  std::cout << t->get_debug_string_r() << "\n" << std::endl;
 
  int awo[13] = {3,5,8,27,42,10,7,666,20,4,22,35,17};
  for (int i = 0; i < 13; i++) {
      t->remove(awo[i]);
      std::cout << "removing: " << awo[i] << "\n" << t->get_debug_string_r() << "\n" << std::endl;
  }

  return 0;
}
