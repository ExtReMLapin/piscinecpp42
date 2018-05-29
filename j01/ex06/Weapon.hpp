#pragma once

#include <string>

class Weapon
{
public:
	Weapon(std::string name);
	~Weapon();
	std::string const &getType();
	void setType(std::string type);
private:
	std::string type;
};