#pragma once

#include "Zombie.hpp"

class ZombieEvent
{
public:
	ZombieEvent();
	~ZombieEvent();
	void setZombieType(std::string type);
	Zombie* newZombie(std::string name) const;
	Zombie *randomChump(void) const;

private:
	std::string type;
	
};