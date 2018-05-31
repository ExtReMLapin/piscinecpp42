#include  "ScavTrap.hpp"

#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
 
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->max_hit_points = 100;
	this->energy_points = 50;
	this->max_energy_points = 50;
	this->level = 1;
	this->melee_attack_dmg = 20;
	this->ranged_attack_dmg = 15;
	this->armor_damage_reduction = 3;
	std::cout << "Hi there comrad, my name is " << this->name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << this->name <<  " just died and said : REEEEEEEEEEEEEEEEEEEE" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &source) : ClapTrap(source)
{
	std::cout << "REEEEEEEEEEEEEEEEEEEE DONT COPY ME REEEE" << std::endl;
	*this = source; // appel de l'op =
}

ScavTrap & ScavTrap::operator=(const ScavTrap & rhs)
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


void ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << this->name << " takes his sniper rifle out and shoots at " << target << ". He deals him " << this->ranged_attack_dmg << " damages" <<std::endl;
}

void ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << this->name << " uses it's head as a hammer and hits " << target << " on the head and deals him " << this->melee_attack_dmg << " damages" <<std::endl;
}

void	ScavTrap::challengeNewcomer(void)
{

	std::string		chall[] = {"lick one of his elbows", "touch his right elbow with his right hand", "lick his nose", "make a cake without flour", "get level 14 with the Piscine C++ because he really need to get a putain de convention de stage before july", "liberer le tibet"};
	if (this->energy_points < 25)
	{
		std::cout << this->name << " : Hey buddy i'm going to need a break before doing that." <<  std::endl;
		return;
	}
	else
	{
		this->energy_points -= 25;
		std::cout << this->name << " tries to " << chall[(rand() % 6)] << " but since he's retarded, it's super ineffective !" << std::endl;
	}
}
