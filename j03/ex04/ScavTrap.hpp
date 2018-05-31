#pragma once

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(ScavTrap const &source);
	ScavTrap & operator=(const ScavTrap & rhs);
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void challengeNewcomer(void);
};