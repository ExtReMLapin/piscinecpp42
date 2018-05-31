#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>

int main(void)
{
	std::cout << "vvvvv TESTING CONSTRUCTOR AND DESTRUCTOR ORDER vvvvv" <<std::endl << std::endl;

	FragTrap *potao = new FragTrap("tata");

	delete potao;
	std::cout <<std::endl << std::endl;
	std::cout << "^^^^^ TESTING CONSTRUCTOR AND DESTRUCTOR ORDER ^^^^^" <<std::endl << std::endl;

	FragTrap potao2 = FragTrap("toto");

	
	potao2.rangedAttack("pigeon");
	potao2.meleeAttack("chèvre");
	potao2.takeDamage(42);
	potao2.beRepaired(42);
	potao2.vaulthunter_dot_exe("Ben Laden");

	return 0;
}