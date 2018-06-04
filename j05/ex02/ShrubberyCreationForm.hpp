#pragma once
#include "Form.hpp"
#include <string>

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		void execute(Bureaucrat const & executor) const;
		std::string getTarget() const;

	private:
		std::string target;
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &source);
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm & rhs);
		
};