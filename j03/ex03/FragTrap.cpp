#include  "FragTrap.hpp"


#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->max_hit_points = 100;
	this->energy_points = 100;
	this->max_energy_points = 100;
	this->level = 1;
	this->melee_attack_dmg = 30;
	this->ranged_attack_dmg = 20;
	this->armor_damage_reduction = 5;
	std::cout << "[CHEERING BEEP] Beep boop human, my name is " << this->name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "[SAD AND LONG BEEP] "  << this->name <<  " just died and said : see you on the other side space cowboy" << std::endl;
}

FragTrap::FragTrap(FragTrap const &source) : ClapTrap(source)
{
	std::cout << "Wow that's a nice copy buddy!" << std::endl;
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
	std::cout << "[SNEAKY BEEP] - " << this->name << " is a coward and decides to attack " << target << " using some long range weapon and deals " << this->ranged_attack_dmg << " damages" << std::endl;
}

void FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "[ANGREE BEEP] - " << this->name << " decides to attack " << target << " using a melee weapon and deals " << this->melee_attack_dmg << " damages" <<std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string		attacks[] = {"Fus ro dah", "Suicide by two shots to the back of the head", "Spoon in the eye", "bayonet charge", "Professional kebab removal service", "Article 49.3"};
	std::srand(std::time(0));
	if (this->energy_points < 25)
	{
		std::cout << this->name << " doesn't have the required energy to do that." <<  std::endl;
		return;
	}
	else
	{
		this->energy_points -= 25;
		std::cout<< "[SICK MADMAN BEEP] - "  << this->name << " uses the special attack : [" << attacks[(rand() % 6)] << "] against " << target << " | It's super effective !" << std::endl;

	}

}

