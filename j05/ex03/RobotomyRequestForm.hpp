#pragma once
#include "Form.hpp"
#include <string>

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		void execute(Bureaucrat const & executor) const;
		std::string getTarget() const;
	private:
		std::string target;
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &source);
		RobotomyRequestForm & operator=(const RobotomyRequestForm & rhs);
		
};