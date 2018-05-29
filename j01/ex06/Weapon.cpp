#include "Weapon.hpp"
#include <string>


Weapon::Weapon(std::string name)
{
	this->type = name;
}

Weapon::~Weapon()
{

}

void Weapon::setType(std::string type)
{
	this->type = type;
}

std::string const &Weapon::getType()
{
	return (this->type);
}
