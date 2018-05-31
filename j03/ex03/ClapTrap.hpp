#pragma once

#include <string>


class ClapTrap
{
public:
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(ClapTrap const &source);
	ClapTrap & operator=(const ClapTrap & rhs);
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string name;

protected:
	unsigned int hit_points;
	unsigned int max_hit_points;
	unsigned int energy_points;
	unsigned int max_energy_points;
	unsigned int level;

	unsigned int melee_attack_dmg;
	unsigned int ranged_attack_dmg;
	unsigned int armor_damage_reduction;
};