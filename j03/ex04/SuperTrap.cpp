
#include "SuperTrap.hpp"
#include <iostream>


SuperTrap::SuperTrap(std::string const name): FragTrap(name), NinjaTrap(name)
{
	this->hit_points = 100;
	this->max_hit_points = 100;
	this->energy_points = 120;
	this->max_energy_points = 120;
	this->level = 1;
	this->melee_attack_dmg = 60;
	this->ranged_attack_dmg = 20;
	this->armor_damage_reduction = 5;
	this->name = name;
	return;
}

SuperTrap::SuperTrap(SuperTrap const & src): FragTrap(src), NinjaTrap(src)
{

	std::cout << "copy supertrap" << std::endl;
	*this = src;
	return;
}

SuperTrap::~SuperTrap()
{

	std::cout << "destroy supertrap" << std::endl;
	return;
}

SuperTrap &  SuperTrap::operator=(SuperTrap const & rhs)
{

	this->hit_points = rhs.hit_points;
	this->max_hit_points = rhs.max_hit_points;
	this->energy_points = rhs.energy_points;
	this->max_energy_points = rhs.max_energy_points;
	this->level = rhs.level;
	this->name = rhs.name;
	this->melee_attack_dmg = rhs.melee_attack_dmg;
	this->ranged_attack_dmg = rhs.ranged_attack_dmg;
	this->armor_damage_reduction = rhs.armor_damage_reduction;
	return (*this);
	return *this;
}

void	SuperTrap::rangedAttack(std::string & target)
{
	FragTrap::rangedAttack(target);
}

void	SuperTrap::meleeAttack(std::string & target)
{
	NinjaTrap::meleeAttack(target);
}