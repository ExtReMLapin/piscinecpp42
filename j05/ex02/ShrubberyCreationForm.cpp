#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(72, 45, "ShrubberyCreationForm")
{
	this->target = target;
}


ShrubberyCreationForm::ShrubberyCreationForm()
{

}

std::string  ShrubberyCreationForm::getTarget()const
{
	return(target);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs)
{
	(void)rhs;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &source)
{
	*this = source; 
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string nm = this->target + "_shrubbery"; 
	const char *fn = nm.c_str();
	if (executor.getGrade() <= this->getGradeExec() && this->getSigned() == true)
	{
		std::ofstream ofs(fn);
		if (ofs)
		{
			//yolo
			ofs <<"        ^" << std::endl <<"       ^^^" << std::endl <<"      ^^^^^" << std::endl <<"     ^^^^^^^" << std::endl <<"        |" << std::endl <<"        ^" << std::endl <<"       ^^^" << std::endl <<"      ^^^^^" << std::endl <<"     ^^^^^^^" << std::endl <<"        |" << std::endl;
			ofs.close();
		}
		
	}
	else if (this->getSigned() == false)
		std::cout << "Hey buddy you might want to sign it first" << std::endl;
	else
		throw Form::GradeTooLowException();
}
 