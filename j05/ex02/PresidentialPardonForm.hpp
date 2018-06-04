#pragma once
#include "Form.hpp"
#include <string>

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();


	private:
		std::string const target;
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &source);
		PresidentialPardonForm & operator=(const PresidentialPardonForm & rhs);
		
};