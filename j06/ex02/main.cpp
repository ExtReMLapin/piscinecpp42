#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base * generate(void)
{
	int rand = std::rand()%3;

	if (rand == 1)
		return (new B());
	if (rand == 2)
		return (new C());
	return (new A());
}

void	identify_from_pointer( Base * p )
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Base" << std::endl;
}

void	identify_from_reference( Base & p )
{
	if (dynamic_cast<A *>(&p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(&p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(&p) != NULL)
		std::cout << "C" << std::endl;
	else	
		std::cout << "Base" << std::endl;
}


int			main(void)
{
	srand(time(NULL)); // c'est lvasseur qui m'a donné son main de test
	Base	*random = generate();

	identify_from_pointer(random);
	identify_from_reference(*random);
	return 0;
}