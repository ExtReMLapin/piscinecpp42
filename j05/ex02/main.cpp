#include "Bureaucrat.hpp"
#include <iostream>
#include "Form.hpp"

int main(void)
{
	Bureaucrat taubira("Taubira", 10);
	Bureaucrat DSK("Dominique-nique", 142);
	Bureaucrat marine("Marine le stylo", 150);


	Form form_high(10,10,"Elite form");

	marine.signForm(form_high);
	
	std::cout << form_high << taubira << std::endl;
	taubira.signForm(form_high);

	std::cout  << form_high;

	try{
		Form dolfi( 5000000,0, "");
	}
	catch (std::exception & e)
	{
		std::cout << "fail creation form" << e.what() << std::endl;
	}


}