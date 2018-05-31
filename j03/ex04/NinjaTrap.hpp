#pragma once

#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"


class NinjaTrap : public virtual ClapTrap
{
public:
	NinjaTrap(std::string name);
	~NinjaTrap();
	NinjaTrap(NinjaTrap const &source);
	NinjaTrap & operator=(const NinjaTrap & rhs);
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	ninjaShoebox(FragTrap const & target);
	void	ninjaShoebox(ScavTrap const & target);
	void	ninjaShoebox(NinjaTrap const & target);
	void	ninjaShoebox(ClapTrap const & target);
};