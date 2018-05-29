#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie()
{
	std::cout << "Created zombie" << std::endl;
	this->type = "Méchant zombie";
	this->name = "bernard";
}

Zombie::~Zombie(void)
{
	std::cout << "Destroyed zombie" << std::endl;
}


void Zombie::announce(void) const
{
	std::cout << "<" << this->name << "(" << type << ")> Braiiiiiiinnnssss..." << std::endl;
}