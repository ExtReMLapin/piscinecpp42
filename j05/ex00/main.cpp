#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat taubira("Taubira", 150);
	Bureaucrat DSK("Dominique-nique", 142);
	Bureaucrat marine("Marine le stylo", 150);

	std::cout << marine;


	try 
	{
		Bureaucrat hitler("Tonton dolfi", 199);
	} 
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}


	try 
	{
		Bureaucrat hitler("Tonton dolfi", 150);
		hitler.decrementGrade();
	} 
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try 
	{
		Bureaucrat hitler("Tonton dolfi", 1);
		hitler.incrementGrade();
	} 
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}



	try 
	{
		Bureaucrat hitler("Tonton dolfi", 199);
	} 
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try 
	{
		Bureaucrat hitler("Tonton dolfi", 0);
	} 
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}







}