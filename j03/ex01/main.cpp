#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
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
	superPotato.challengeNewcomer();
	superPotato.challengeNewcomer();
	superPotato.challengeNewcomer();
	superPotato.takeDamage(1);
	superPotato.takeDamage(42);
	superPotato.takeDamage(42);
	superPotato.beRepaired(44);
	superPotato.takeDamage(42);


	return 0;
}