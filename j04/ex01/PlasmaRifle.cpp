#include "PlasmaRifle.hpp"

#include <iostream>

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21)
{

}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src)
{
	*this = src;
}


PlasmaRifle &	PlasmaRifle::operator=(PlasmaRifle const & rhs)
{
	this->name = rhs.name;
	this->damage = rhs.damage;
	this->shooting_cost = rhs.shooting_cost;
	return (*this);
}

PlasmaRifle::~PlasmaRifle()
{

}

void PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}