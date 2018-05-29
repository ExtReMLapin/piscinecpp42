#include "Pony.hpp"
#include <iostream>

Pony::Pony()
{
	std::cout << "Created at adr " << this << std::endl;
}

Pony::~Pony()
{
	std::cout << "Destroyed at adr " << this << std::endl;
}

void Pony::check(int *i) {
      int j;
      if ((i < &j) == ((void*)this < (void*)&j))
         std::cout << "Allocated on the Stack" << std::endl;
      else
         std::cout << "Allocated on the Heap" << std::endl;
   }
/*
** Thats a dirty hack but it works
** we create an int on the stack before creating the class
** Then we create another int on the stack in this function and compare the order, if it's the same then its on the stack, else, its not
** The heap is usually created with a far lower adr than the stack if im not wrong so there is no change on macos it "above"
*/