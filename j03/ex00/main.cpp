#include "FragTrap.hpp"

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
	

	/*FragTrap yala = FragTrap(tomato42);
	yala.takeDamage(42);*/


	return 0;
}