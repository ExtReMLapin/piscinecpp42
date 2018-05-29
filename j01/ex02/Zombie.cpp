#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(std::string name, std::string type)
{
	std::cout << "Created zombie" << std::endl;
	this->type = type;
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << "Destroyed zombie" << std::endl;
}


void Zombie::announce(void) const
{
	std::cout << "<" << this->name << "(" << type << ")> Braiiiiiiinnnssss..." << std::endl;
}