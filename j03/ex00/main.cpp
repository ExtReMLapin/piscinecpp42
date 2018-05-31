#include "FragTrap.hpp"

int main(void)
{
	FragTrap *tomato0 = new FragTrap("TORBLERON");
	tomato0->beRepaired(48);

	FragTrap *tomato42 = FragTrap(tomato0);
	delete tomato0;
	tomato42->beRepaired(44);

	tomato42->rangedAttack("Cpt. Kebab");
	tomato42->meleeAttack("some bird");
		

	return 0;
}