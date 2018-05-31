#include  "ScavTrap.hpp"

#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
 
ScavTrap::ScavTrap(std::string name) : hit_points(100), max_hit_points(100), energy_points(50), max_energy_points(50), level(1), melee_attack_dmg(20), ranged_attack_dmg(15), armor_damage_reduction(3)
{
	this->name = name;
	std::cout << "Hi there comrad, my name is " << this->name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << this->name <<  " just died and said : REEEEEEEEEEEEEEEEEEEE" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &source)
{
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

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points == 0)
	{
		std::cout << this->name << " : stop hurting me yer fokin prick, i'm already dead" << std::endl;
		return;
	}

	if (amount <= this->armor_damage_reduction)
	{
		amount = 0;
		std::cout << this->name << " : did you really think you could hurt me with yer toy ?" << std::endl;
		return;
	}
	else
		amount -= this->armor_damage_reduction;
	if (amount >= this->hit_points)
	{
		this->hit_points = 0;
		std::cout << this->name << " : dang, it hurts, i just took " << amount << " damages and i'm fokin dying." << std::endl;
		return;
	}
	else
	{
		std::cout << this->name << " : dang, it hurts, i just took  " << amount << " damages : " << this->hit_points << "HP -> ";
		this->hit_points -= amount;
		std::cout << this->hit_points << "HP." << std::endl;
	}

}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points == this->max_hit_points)
	{
		std::cout  << this->name << " : ey mate why yer making me repair myself, i'm already all good !" << std::endl;
		return;
	}

	if (amount + this->hit_points > this->max_hit_points)
		amount = this->max_hit_points - this->hit_points;
	std::cout << this->name << " : Bloody hell i really needed this repair, i'm healing myself with " << amount << "HP";
	this->hit_points = std::min( this->hit_points + amount, this->max_hit_points);
	std::cout << " and i now have " << this->hit_points  << " HP" << std::endl;
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
