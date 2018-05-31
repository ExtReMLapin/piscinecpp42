#include "ClapTrap.hpp"
#include <string>
#include <iostream>
ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap was created" <<std::endl;
	this->name = name;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap was destroyed" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &source)
{
	*this = source; // appel de l'op =
}

ClapTrap & ClapTrap::operator=(const ClapTrap & rhs)
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
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points == 0)
	{
		std::cout << this->name << " is already dead but someone is attacking it" << std::endl;
		return;
	}

	if (amount <= this->armor_damage_reduction)
	{
		amount = 0;
		std::cout << this->name << " was attacked but didn't take any damage because of his armor " << std::endl;
		return;
	}
	else
		amount -= this->armor_damage_reduction;
	if (amount >= this->hit_points)
	{
		this->hit_points = 0;
		std::cout << this->name << " just took " << amount << " damages and died." << std::endl;
		return;
	}
	else
	{
		std::cout << this->name << " just took " << amount << " damages : " << this->hit_points << "HP -> ";
		this->hit_points -= amount;
		std::cout << this->hit_points << "HP." << std::endl;
	}

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points == this->max_hit_points)
	{
		std::cout << this->name << " is trying to repair itself even if it's useless " << std::endl;
		return;
	}

	if (amount + this->hit_points > this->max_hit_points)
		amount = this->max_hit_points - this->hit_points;
	std::cout << this->name << " is being repaired, he gains " << amount << " HP";
	this->hit_points = std::min( this->hit_points + amount, this->max_hit_points);
	std::cout << " and has now " << this->hit_points  << " HP" << std::endl;
}