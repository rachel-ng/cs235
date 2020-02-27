#include <iostream>
#include <stdexcept>
#include "List.h"
int main()
{
  List *l = new List();
   std::cout << l->getDebugString() << "\n";

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
   l->pushback("last");
   std::cout << l->getDebugString() << "\n";
   l->pushback("stan bts");
   std::cout << l->length() << " items in the list.\n";
   std::cout << l->getDebugString() << "\n";
   
   l->remove(1);

   std::cout << l->length() << " items in the list.\n";
   std::cout << l->getDebugString() << "\n";

   try {
    (*l)[-100] = "rip";
    } catch (const std::out_of_range& err) {
        std::cout << "tried (*l)[-100]: out of range!!!" << std::endl;
    }
   delete l;
   std::cout << "The end\n";
   return 0;
}
