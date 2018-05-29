#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>

int main(void)
{
	ZombieEvent zEvent;

	zEvent.setZombieType("ZombieLol");

	Zombie *labadi = zEvent.randomChump();

	delete labadi;
	Zombie potato = Zombie("Robert", "Zombie pas tres gentil");
	potato.announce();

	return 0;
}