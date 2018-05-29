#include "Pony.hpp"
#include <iostream>

static void ponyOnTheHeap(void)
{
	int i = 42;
	Pony *petitponey = new Pony();
	petitponey->check(&i);
	delete petitponey;
}

static void ponyOnTheStack(void)
{
	int i = 42;
	Pony petitponey;
	petitponey.check(&i);
}


int main(void)
{
	std::cout << std::endl << "Calling ponyOnTheHeap" << std::endl;
	ponyOnTheHeap();
	std::cout << std::endl << "Calling ponyOnTheStack" << std::endl;
	ponyOnTheStack();
	return 0;
}
