#pragma once

#include <string>

class ScavTrap
{
public:
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(ScavTrap const &source);
	ScavTrap & operator=(const ScavTrap & rhs);
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void challengeNewcomer(void);
private:
	unsigned int hit_points;
	unsigned int max_hit_points;
	unsigned int energy_points;
	unsigned int max_energy_points;
	unsigned int level;
	std::string name;
	unsigned int melee_attack_dmg;
	unsigned int ranged_attack_dmg;
	unsigned int armor_damage_reduction;
};