#include "NinjaTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
 
NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 60;
	this->max_hit_points = 60;
	this->energy_points = 120;
	this->max_energy_points = 120;
	this->level = 1;
	this->melee_attack_dmg = 60;
	this->ranged_attack_dmg = 5;
	this->armor_damage_reduction = 0;
	std::cout << "Hi there jean naruto, my name is " << this->name << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << this->name <<  " just died without making any noise" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &source) : ClapTrap(source)
{
	std::cout << "A ninja uses black magic to duplicate himself " << std::endl;
	*this = source; // appel de l'op =
}

NinjaTrap & NinjaTrap::operator=(const NinjaTrap & rhs)
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


void NinjaTrap::rangedAttack(std::string const & target)
{
	std::cout << this->name << " threw some shuriken at " << target << ". He deals him " << this->ranged_attack_dmg << " damages" <<std::endl;
}

void NinjaTrap::meleeAttack(std::string const & target)
{
	std::cout << this->name << " tried to break " << target << "'s neck and deals him " << this->melee_attack_dmg << " damages" <<std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap const & target)
{
	std::cout << this->name << " throws a baby at " << target.name << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap const & target)
{
	std::cout << this->name << " throw some expired food at " << target.name << std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap const & target)
{

	std::cout << this->name << " sees himself in a mirrors and doesn't do shit to " << target.name << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap const & target)
{
	std::cout << this->name << " ignores " << target.name << std::endl;
}
