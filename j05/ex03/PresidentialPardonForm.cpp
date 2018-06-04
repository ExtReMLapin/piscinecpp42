#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>


PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(25, 5, "PresidentialPardonForm")
{
	this->target = target;
}

std::string  PresidentialPardonForm::getTarget() const
{
	return(target);
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

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= this->getGradeExec() && this->getSigned() == true)
		std::cout << this->target << " has been pardonned by Zafod Beeblebrox." << std::endl;
	else if (this->getSigned() == false)
		std::cout << "Hey buddy you might want to sign it first" << std::endl;
	else
		throw Form::GradeTooLowException();
}
