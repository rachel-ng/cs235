#include <iostream>
#include "List.h"
int main()
{
  List *l = new List();

  l->insert("one");
  l->insert("two");
  l->insert("three");
   l->insert("four");

   std::cout << l->length() << " items in the list.\n";
   std::cout << l->getDebugString() << "\n";

   std::cout << (*l)[0] << std::endl;
   std::cout << (*l)[1] << std::endl;
   std::cout << (*l)[2] << std::endl;
   std::cout << (*l)[3] << std::endl;
   (*l)[2] = "rip";
   
   l->insert("five");
   l->insert("six");
   l->insert("seven");

   std::cout << l->length() << " items in the list.\n";
   std::cout << l->getDebugString() << "\n";
   
   l->remove(1);

   std::cout << l->length() << " items in the list.\n";
   std::cout << l->getDebugString() << "\n";



   delete l;
   std::cout << "The end\n";
   return 0;
}
