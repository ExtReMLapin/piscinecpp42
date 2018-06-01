#pragma once

#include <string>

class AWeapon
{
public:
	AWeapon(AWeapon const & src);
	virtual ~AWeapon();
	AWeapon &	operator=(AWeapon const & rhs);

	AWeapon(std::string const & name, int apcost, int damage);
	std::string const &getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;
protected:
	AWeapon();
	std::string name;
	unsigned int damage;
	unsigned int shooting_cost;
};