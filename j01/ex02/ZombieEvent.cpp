#include "ZombieEvent.hpp"
#include <iostream>
#include <ctime>

ZombieEvent::ZombieEvent()
{
	std::cout << "Created ZombieEvent" << std::endl;
}

ZombieEvent::~ZombieEvent(void)
{
	std::cout << "Destroyed ZombieEvent" << std::endl;
}


void ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}


Zombie *ZombieEvent::newZombie(std::string name) const
{
	Zombie *newzom = new Zombie(name, this->type);

	return (newzom);
}


Zombie *ZombieEvent::randomChump(void) const
{
	std::srand(std::time(nullptr)); // bein oui
	std::string		tab[] = {"Roger", "Ben", "Laden", "Yabonanenebanana", "goulalibi"};
	Zombie* 		zombie = this->newZombie(tab[std::rand() % 5]);
	zombie->announce();
	return (zombie);
}