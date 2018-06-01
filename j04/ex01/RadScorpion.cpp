#include "RadScorpion.hpp"

#include <iostream>

RadScorpion::RadScorpion() : Enemy(80 ,"RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const & src) : Enemy(src.hit_points, src.type)
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion &RadScorpion::operator=(RadScorpion const & rhs)
{
	this->hit_points = rhs.hit_points;
	this->type = rhs.type;
	return (*this);
}

void 		RadScorpion::takeDamage(int damage)
{
	return Enemy::takeDamage(damage);
}
