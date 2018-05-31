#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include <iostream>

int main(void)
{

	SuperTrap potao2 = SuperTrap("Jean-Naruto");
	std::string lol = "pomm";
	potao2.takeDamage(42);
	potao2.meleeAttack(lol);
	potao2.rangedAttack(lol);

	return 0;
}