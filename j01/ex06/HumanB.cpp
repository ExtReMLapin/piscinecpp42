#include "HumanB.hpp"

#include <string>
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	this->name = name;
}


HumanB::~HumanB()
{

}


void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack() const
{
	if (this->weapon == NULL)
		return;
	std::cout << this->name << " attacks with his " << this->weapon->getType() <<  std::endl;
}
