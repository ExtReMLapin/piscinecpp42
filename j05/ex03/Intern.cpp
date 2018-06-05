#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
Intern::Intern(void)
{

}
 
Intern::~Intern(void)
{

}


static Form *_ShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static Form *_RobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static Form *_PresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}






Form * Intern::makeForm(std::string form, std::string target)
{



	if (form == "shrubbery creation")
	{
		std::cout << "Intern creates " << form << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	else if (form == "robotomy request")
	{
		std::cout << "Intern creates " << form << std::endl;
		return (new RobotomyRequestForm(target));
	}
	else if (form == "presidential pardon")
	{
		std::cout << "Intern creates " << form << std::endl;
		return (new PresidentialPardonForm(target));
	}
	std::cout << "Requested form unknown." << std::endl;
	return (NULL);

}

Intern::Intern(Intern const & src)
{
	*this = src;
}

Intern & Intern::operator=( Intern const & src)
{
	(void)src;
	return (*this);
}

