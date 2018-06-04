#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(72, 45, "RobotomyRequestForm")
{
	this->target = target;
}


RobotomyRequestForm::RobotomyRequestForm()
{

}


std::string RobotomyRequestForm::getTarget()const
{
	return(target);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs)
{
	(void)rhs;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &source)
{
	*this = source; 
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() <= this->getGradeExec() && this->getSigned() == true)
		
		{
			std::cout << "*Bzzzzzzrrrffffttrrrrfflllll*" << std::endl;
			if (rand() % 2 == 0) // de zéro à  1
				std::cout << this->target << " has been robotomized successfully." << std::endl;
			else
				std::cout << "Woops, the robotimisation failed, you drilled your own hand." << std::endl;
		}
	else if (this->getSigned() == false)
		std::cout << "Hey buddy you might want to sign it first" << std::endl;
	else
		throw Form::GradeTooLowException();
}
