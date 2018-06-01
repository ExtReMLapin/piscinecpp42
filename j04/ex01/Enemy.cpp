#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type) : hit_points(hp), type(type)
{

}

Enemy::Enemy()
{
	
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
}

Enemy::~Enemy()
{

}

Enemy &	Enemy::operator=(Enemy const & rhs)
{
	this->hit_points = rhs.hit_points;
	this->type = rhs.type;
	return (*this);
}

std::string const &Enemy::getType() const
{
	return (this->type);
}

int Enemy::getHP() const
{
	return (this->hit_points);
}

void Enemy::takeDamage(int amount)
{
	if (amount < 0)
		return;
	if (amount >= this->hit_points)
	{
		this->hit_points = 0;
		return;
	}
	this->hit_points -= amount;
}