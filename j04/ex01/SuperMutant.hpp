#pragma once

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
	SuperMutant();
	~SuperMutant();
	SuperMutant(SuperMutant const & src);
	SuperMutant &	operator=(SuperMutant const & rhs);
	virtual void takeDamage(int damage);
};