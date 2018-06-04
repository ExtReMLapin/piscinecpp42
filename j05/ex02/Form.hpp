#pragma once

#include <string>


class Bureaucrat;

class Form
{

	public:
		Form(unsigned int gradeSign, unsigned int gradeExec, std::string name);
		~Form();
		unsigned int getGradeSign() const;
		unsigned int getGradeExec() const;
		std::string getName() const;
		bool getSigned()const;
		void beSigned(Bureaucrat &toto);
		virtual void execute(Bureaucrat const & executor) const = 0;
		virtual std::string getTarget() const = 0;
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
	private:
		unsigned int const _gradeSign;
		unsigned int const _gradeExec;
		std::string const _name;
		bool _signed;
		Form(Form const &source);
		Form & operator=(const Form & rhs);
	protected :
		Form();
};
std::ostream &operator<<(std::ostream &o, Form &rhs);