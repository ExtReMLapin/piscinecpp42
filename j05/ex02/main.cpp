#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <cstdlib>


int main(void)
{
	Bureaucrat Buro1("Procureur de la République", 1);
	Bureaucrat Buro2("Taubira", 140); // bah ouais ma grosse tu fais mal ton taf

	PresidentialPardonForm president("Micron");
	ShrubberyCreationForm foret("Foret d'elwynn");
	RobotomyRequestForm beepboop("Roger le (pas encore) robot de l'espace nazi venu du futur");


	//ca passe easy
	Buro1.signForm(president);
	Buro1.executeForm(president);

	// error now
	Buro2.signForm(beepboop);
	std::cout <<"Taubira : pk sa march pa :(((" << std::endl;
	std::cout <<"Le Procureur de la République : Putain Taubira t'es chiante, tu fais de la merde, laisse moi faire." << std::endl;
	std::cout <<"Taubira : gngngng j'entends rien" << std::endl;

	Buro1.signForm(beepboop);


	std::cout <<"Le Procureur de la République : voilaaa." <<std::endl;


	Buro2.executeForm(beepboop);


	std::cout <<"Taubira : arrr ca march toujour pa :((" << std::endl;


	std::cout <<"Le Procureur de la République : TAUBIRA PUTAIN TU CASSE LES COUILLES TOUCHE PAS BORDEL" << std::endl;
	std::cout <<"Le Procureur de la République : Bon." << std::endl;
	std::cout <<"Le Procureur de la République : Vas-y, je le fais mais après tu retourne écrire tes bouquins de merde que personne lis." << std::endl;
	std::cout <<"Taubira : ui ui ui" << std::endl;


	Buro1.executeForm(beepboop);

	// test file creation 
	Buro1.signForm(foret);
	Buro1.executeForm(foret);
	return(1);

}