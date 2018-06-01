#include <iostream>
#include "Character.hpp"
#include <string>
#include <algorithm>
class Enemy;
class AWeapon;

Character::Character(std::string const & name) : name(name), weapon(NULL), action_points(40)
{
}

Character::Character()
{
}

Character::Character(Character const & src) : name(src.name), weapon(src.weapon), action_points(src.action_points)
{
}

Character::~Character()
{
}

Character & Character::operator=(Character const & src)
{
	if (this != &src) {
		this->action_points = src.action_points;
		this->weapon = src.weapon;
	}
	return *this;
}

void Character::recoverAP()
{
	this->action_points = std::min(40, this->action_points + 10);
}

void Character::equip(AWeapon* weapon)
{
	this->weapon =  weapon;
}

void Character::attack(Enemy* enemy)
{
	if (!this->weapon)
		return;

	if (this->action_points >= this->weapon->getAPCost())
	{
		action_points -= this->weapon->getAPCost();
		enemy->takeDamage(this->weapon->getDamage());
		std::cout << this->name <<" attacks "<< enemy->getType() <<" with a "<< this->weapon->getName() << std::endl;
		this->weapon->attack();
		if (enemy->getHP() == 0)
			delete enemy;
	}

}

std::string const &	Character::getName() const
{
	return this->name;
}

int  Character::getAP() const
{
	return this->action_points;
}

AWeapon *Character::getWeapon() const
{
	return this->weapon;
}

std::ostream & operator<<(std::ostream & o, Character const & src)
{
	if (src.getWeapon())
		o << src.getName()<< " has "<< src.getAP() <<" AP and wields a " << src.getWeapon()->getName() << std::endl;
	else
		o << src.getName()<< " has "<< src.getAP() <<" AP and is unarmed" << std::endl;
	return o;
}