#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : name(name), damage(damage), shooting_cost(apcost)
{

}

AWeapon::AWeapon()
{
	
}

AWeapon::AWeapon(AWeapon const & src)
{
	*this = src;
}

AWeapon::~AWeapon()
{

}

AWeapon &	AWeapon::operator=(AWeapon const & rhs)
{
	this->name = rhs.name;
	this->damage = rhs.damage;
	this->shooting_cost = rhs.shooting_cost;
	return (*this);
}


std::string const &AWeapon::getName() const
{
	return (this->name);
}

int AWeapon::getAPCost() const
{
	return (this->shooting_cost);
}

int AWeapon::getDamage() const
{
	return (this->damage);
}
