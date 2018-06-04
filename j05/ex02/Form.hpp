#pragma once

#include <string>


class Bureaucrat;

class Form
{

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
			GradeTooHighException();
			~GradeTooHighException() throw();
			GradeTooHighException(Form::GradeTooHighException const &source);
			GradeTooHighException & operator=(const Form::GradeTooHighException & rhs);
			
	};


	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
			GradeTooLowException();
			~GradeTooLowException() throw();
			GradeTooLowException(Form::GradeTooLowException const &source);
			GradeTooLowException & operator=(const Form::GradeTooLowException & rhs);
			
	};





	public:
		Form(unsigned int gradeSign, unsigned int gradeExec, std::string name);
		~Form();
		unsigned int getGradeSign() const;
		unsigned int getGradeExec() const;
		std::string getName() const;
		bool getSigned()const;
		void beSigned(Bureaucrat &toto);
	private:
		unsigned int const _gradeSign;
		unsigned int const _gradeExec;
		std::string const _name;
		bool _signed;
		Form();
		Form(Form const &source);
		Form & operator=(const Form & rhs);
};
std::ostream &operator<<(std::ostream &o, Form &rhs);