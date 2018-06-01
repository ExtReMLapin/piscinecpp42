#pragma once

#include "Enemy.hpp"

class RadScorpion : public Enemy
{
public:
	RadScorpion();
	~RadScorpion();
	RadScorpion(RadScorpion const & src);
	RadScorpion &	operator=(RadScorpion const & rhs);
	virtual void takeDamage(int damage);
};