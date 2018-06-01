#pragma once

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle(PlasmaRifle const & src);
	~PlasmaRifle();
	PlasmaRifle();
	PlasmaRifle &	operator=(PlasmaRifle const & rhs);
	void attack() const;
};