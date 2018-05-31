#include  "FragTrap.hpp"

#include <string>
#include <iostream>
#include <algorithm>

FragTrap::FragTrap(std::string name) : hit_points(100), max_hit_points(100), energy_points(100), max_energy_points(100),level(1), melee_attack_dmg(30), ranged_attack_dmg(20), armor_damage_reduction(5)
{
	this->name = name;
	std::cout << "[CHEERING BEEP] Beep boop human, my name is " << this->name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "[SAD AND LONG BEEP] see you on the other side space cowboy" << std::endl;
}

FragTrap::FragTrap(FragTrap const &source)
{
	*this = source; // appel de l'op =
}

FragTrap & FragTrap::operator=(const FragTrap & rhs)
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



void FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "[SNEAKY BEEP] - " << this->name << " is a coward and decides to attack " << target << " using some long range weapon and deals " << this->ranged_attack_dmg << " damages" <<std::endl;
}

void FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "[ANGREE BEEP] - " << this->name << " decides to attack " << target << " using a melee weapon and deals " << this->melee_attack_dmg << " damages" <<std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	
	if (amount < this->hit_points)
	{
		this->hit_points = 0;
		std::cout << "[WINDOWS XP LOGOUT SOUND] - " << this->name << " just took " << amount << " damages and died." << std::endl;
		return;
	}
	else
	{
		std::cout << "[PANICKED BEEP] - " << this->name << " just took " << amount << " damages : " << this->hit_points << "HP -> ";
		this->hit_points -= amount;
		std::cout << this->hit_points << "HP." << std::endl;
	}

}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points == this->max_hit_points)
	{
		std::cout << "[STRONG BEEP] - " << this->name << " is trying to repair itself even if it's useless " << std::endl;
		return;
	}

	if (amount + this->hit_points > this->max_hit_points)
		amount = this->max_hit_points - this->hit_points;
	std::cout << "[HAPPY BEEP] - " << this->name << " is being repaired, he gains " << amount << " HP";
	this->hit_points = std::min( this->hit_points + amount, this->max_hit_points);
	std::cout << " and has now " << this->hit_points  << " HP" << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string		attacks[] = {"Fus ro dah", "Suicide by two shots to the back of the head", "Spoon in the eye", "bayonet charge", "Professional kebab removal service"};

	if (this->energy_points < 25)
	{
		std::cout << this->name << " doesn't have the required energy to do that." <<  std::endl;
		return;
	}
	else
	{
		this->energy_points -= 25;
		std::cout << this->name << " uses the special attack : " << attacks[(rand() % 5)] << " against " << target << " It's super effective !" << std::endl;

	}

}

