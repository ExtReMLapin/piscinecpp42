#pragma once

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
	PowerFist(PowerFist const & src);
	~PowerFist();
	PowerFist();
	PowerFist &	operator=(PowerFist const & rhs);
	void attack() const;
};