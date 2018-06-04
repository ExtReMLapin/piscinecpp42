#pragma once

#include "Form.hpp"

class Intern 
{
	public:
		Intern(void);
		~Intern(void);
		Form * makeForm(std::string form, std::string target);

	private:
		Intern(Intern const & src);
		Intern & operator=( Intern const & src);

};