#pragma once

#include <string>
#include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string name, Weapon &Weapon);
	~HumanA();
	void attack() const;
	private:
		std::string name;
		Weapon *weapon;
};