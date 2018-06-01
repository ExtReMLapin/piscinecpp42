#pragma once

#include <string>
#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{

public:
	Character(std::string const & name);
	Character(Character const &);
	~Character();
	Character & operator=(Character const &);
	void recoverAP();
	void equip(AWeapon*);
	void attack(Enemy*);
	std::string const &getName() const;
	int getAP() const;
	AWeapon *	getWeapon()const;
private:
	Character();
	std::string const		name;
	AWeapon	*				weapon;
	int						action_points;
};

std::ostream & operator<<(std::ostream & o, Character const & src);