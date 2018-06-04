#pragma once
#include "Form.hpp"
#include <string>

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		void execute(Bureaucrat const & executor) const;
		std::string getTarget() const;

	private:
		std::string target;
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &source);
		PresidentialPardonForm & operator=(const PresidentialPardonForm & rhs);
		
};