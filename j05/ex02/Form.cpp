#include "Form.hpp"

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

Form::Form(unsigned int gradeSign, unsigned int gradeExec, std::string name) : _gradeSign(gradeSign), _gradeExec(gradeExec), _name(name),  _signed(false)
{
	if (this->_gradeSign < 1 || _gradeExec < 1)
		throw Form::GradeTooHighException();
	else if (this->_gradeSign > 150 || _gradeExec > 150)
		throw Form::GradeTooLowException();
}


Form::Form() : _gradeSign(0), _gradeExec(0), _name("ERROR")
{

}


Form::~Form()
{

}

Form & Form::operator=(const Form & rhs)
{
	(void)rhs;
	return (*this);
}

Form::Form(Form const &source) : _gradeSign(0), _gradeExec(0), _name("ERROR")
{
	*this = source; 
}


unsigned int Form::getGradeSign() const
{
	return (this->_gradeSign);
}
unsigned int Form::getGradeExec() const
{
	return (this->_gradeExec);
}
std::string Form::getName() const
{
	return (this->_name);
}
bool Form::getSigned() const
{
	return (this->_signed);
}


void Form::beSigned(Bureaucrat &toto)
{
	if (toto.getGrade() > this->_gradeSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}



const char* Form::GradeTooHighException::what() const throw()
{
	return ("Number is too low which makes the grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Number is too high, which makes the grade too low");
}


Form::GradeTooHighException::GradeTooHighException()
{}

Form::GradeTooHighException::~GradeTooHighException() throw()
{}

Form::GradeTooLowException::GradeTooLowException()
{}

Form::GradeTooLowException::~GradeTooLowException() throw()
{}

Form::GradeTooLowException & Form::GradeTooLowException::operator=(const Form::GradeTooLowException & rhs)
{
	(void)rhs;
	return (*this);
}

Form::GradeTooHighException & Form::GradeTooHighException::operator=(const Form::GradeTooHighException & rhs)
{
	(void)rhs;
	return (*this);
}


Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &source)
{
	(void)source;
}

Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &source)
{
	(void)source;
}


std::ostream &operator<<(std::ostream &o, Form &rhs) {
	o << "Form -> Name :" << rhs.getName() << ", is signed : " << rhs.getSigned() << ", Required grade to sign : " << rhs.getGradeSign() <<  ", Required grade to execute : " << rhs.getGradeExec() << std::endl;
	return(o);
}