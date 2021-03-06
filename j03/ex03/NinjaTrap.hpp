#pragma once

#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


class NinjaTrap : public ClapTrap
{
public:
	NinjaTrap(std::string name);
	~NinjaTrap();
	NinjaTrap(NinjaTrap const &source);
	NinjaTrap & operator=(const NinjaTrap & rhs);
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	ninjaShoebox(FragTrap & target);
	void	ninjaShoebox(ScavTrap & target);
	void	ninjaShoebox(NinjaTrap & target);
	void	ninjaShoebox(ClapTrap & target);
};