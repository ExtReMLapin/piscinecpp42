#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"

#include <iostream>

int main(void)
{
	std::cout << "vvvvv TESTING CONSTRUCTOR AND DESTRUCTOR ORDER vvvvv" <<std::endl << std::endl;

	FragTrap *potao = new FragTrap("tata");

	delete potao;
	std::cout <<std::endl << std::endl;
	std::cout << "^^^^^ TESTING CONSTRUCTOR AND DESTRUCTOR ORDER ^^^^^" <<std::endl << std::endl;


	FragTrap *tomato0 = new FragTrap("TORBLERON");
	FragTrap tomato42 = *tomato0;
	delete tomato0;
	
	tomato42.rangedAttack("Cpt. Kebab");
	tomato42.meleeAttack("some bird");
	tomato42.vaulthunter_dot_exe("Ben Laden");
	tomato42.takeDamage(42);
	tomato42.takeDamage(42);
	tomato42.beRepaired(44);
	tomato42.takeDamage(42);
	

	ScavTrap superPotato = ScavTrap("Sgt Garcia");
	superPotato.rangedAttack("Cpt. Kebab");
	superPotato.meleeAttack("some bird");
	superPotato.challengeNewcomer();
	superPotato.takeDamage(1);
	superPotato.takeDamage(42);
	superPotato.takeDamage(42);
	superPotato.beRepaired(44);
	superPotato.takeDamage(42);

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