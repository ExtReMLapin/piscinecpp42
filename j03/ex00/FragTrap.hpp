#pragma once

#include <string>

class FragTrap
{
public:
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(FragTrap const &source);
	FragTrap & operator=(const FragTrap & rhs);
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void vaulthunter_dot_exe(std::string const & target);
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