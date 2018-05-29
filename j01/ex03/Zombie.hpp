#pragma once

#include <string>

class Zombie
{
public:
	Zombie(void);
	~Zombie(void);
	void announce(void) const;
	std::string type;
	std::string name;
};