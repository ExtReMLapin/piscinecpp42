#pragma once

#include <string>


class Bureaucrat {
	public:

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
				GradeTooHighException();
				~GradeTooHighException() throw();
				GradeTooHighException(Bureaucrat::GradeTooHighException const &source);
				GradeTooHighException & operator=(const Bureaucrat::GradeTooHighException & rhs);

				
		};


		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
				GradeTooLowException();
				~GradeTooLowException() throw();
				GradeTooLowException(Bureaucrat::GradeTooLowException const &source);
				GradeTooLowException & operator=(const Bureaucrat::GradeTooLowException & rhs);	
		};
		

		Bureaucrat(std::string name, unsigned int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &source);
		Bureaucrat & operator=(const Bureaucrat & rhs);
		std::string getName() const;
		unsigned int getGrade() const;
		void incrementGrade();
		void decrementGrade();
	private:
		std::string const name;
		unsigned int _grade;
		Bureaucrat();
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &rhs);
