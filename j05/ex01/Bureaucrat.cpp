#include "Bureaucrat.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : name(name), _grade(grade)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}


Bureaucrat::Bureaucrat() : name("ERROR"), _grade(1)
{
	throw std::out_of_range( "you should not call this constructor" );
}


Bureaucrat::~Bureaucrat()
{

}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & rhs)
{
	this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::Bureaucrat(Bureaucrat const &source)
{
	*this = source; 
}


void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}
unsigned int Bureaucrat::getGrade() const
{
	return (this->_grade);
}


void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception & e)
	{
		std::cout << this->getName() << " cannot signs " << form.getName() << " because " << e.what() << std::endl;

		return;
	}

}

std::ostream &operator<<(std::ostream &o, Bureaucrat &rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return(o);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Number is too low, which makes the grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Number is too high, which makes the grade too low");
}



Bureaucrat::GradeTooHighException::GradeTooHighException()
{}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{}

Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(const Bureaucrat::GradeTooLowException & rhs)
{
	(void)rhs;
	return (*this);
}

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=(const Bureaucrat::GradeTooHighException & rhs)
{
	(void)rhs;
	return (*this);
}


Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &source)
{
	(void)source;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &source)
{
	(void)source;
}

