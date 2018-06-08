#include "span.hpp"
#include <iostream>
#include <exception>


int main()
{
	Span sp = Span(5000000); 
	sp.fillRandom();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	try{
		sp.addNumber(42);
	}

	catch (std::exception &e)
	{
		 std::cout << e.what() << std::endl;
	}

}
