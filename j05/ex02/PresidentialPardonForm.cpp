#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : target(target)
{

}


PresidentialPardonForm::PresidentialPardonForm()
{

}


PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & rhs)
{
	(void)rhs;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &source)
{
	*this = source; 
}

