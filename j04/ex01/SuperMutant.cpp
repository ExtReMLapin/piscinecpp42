#include "SuperMutant.hpp"

#include <iostream>

SuperMutant::SuperMutant() : Enemy(170 ,"Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const & src) : Enemy(src.hit_points, src.type)
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ..." << std::endl;
}

SuperMutant &SuperMutant::operator=(SuperMutant const & rhs)
{
	this->hit_points = rhs.hit_points;
	this->type = rhs.type;
	return (*this);
}

void 		SuperMutant::takeDamage(int damage)
{
	return Enemy::takeDamage(damage - 3);
}
