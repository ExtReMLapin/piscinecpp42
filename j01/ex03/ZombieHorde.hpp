#pragma once

#include "Zombie.hpp"

class ZombieHorde
{
public:
	ZombieHorde(int N);
	~ZombieHorde();
	void announce(void);
private:
	Zombie *list;
	int len;
};