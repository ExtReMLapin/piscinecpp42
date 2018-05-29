#include "HumanA.hpp"

#include <string>
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
{
	this->weapon = &weapon;
	this->name = name;
}

HumanA::~HumanA()
{

}

void HumanA::attack() const
{
	if (this->weapon == NULL)
		return;
	std::cout << this->name << " attacks with his " << this->weapon->getType() <<  std::endl;
}
