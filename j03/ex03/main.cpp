#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"

#include <iostream>

int main(void)
{

	NinjaTrap potao2 = NinjaTrap("Jean-Naruto");




	potao2.rangedAttack("un japonais");
	potao2.meleeAttack("un pigeon");



	NinjaTrap *ninja = new NinjaTrap("ninjatrap");
	ClapTrap *clap = new ClapTrap("claptrap");
	ScavTrap *scalv = new ScavTrap("scalvtrap");
	FragTrap *frag = new FragTrap("fragtrap");
	potao2.ninjaShoebox(*ninja);
	potao2.ninjaShoebox(*clap);
	potao2.ninjaShoebox(*scalv);
	potao2.ninjaShoebox(*frag);

	return 0;
}