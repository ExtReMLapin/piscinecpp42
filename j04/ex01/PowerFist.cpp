#include "PowerFist.hpp"

#include <iostream>

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50)
{

}

PowerFist::PowerFist(PowerFist const & src)
{
	*this = src;
}


PowerFist &	PowerFist::operator=(PowerFist const & rhs)
{
	this->name = rhs.name;
	this->damage = rhs.damage;
	this->shooting_cost = rhs.shooting_cost;
	return (*this);
}

PowerFist::~PowerFist()
{

}

void PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}