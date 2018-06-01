#pragma once
#include <string>

class Enemy
{
public:
	Enemy(int hp, std::string const & type);

	virtual ~Enemy();
	Enemy(Enemy const & src);

	Enemy &	operator=(Enemy const & rhs);
	std::string const &getType() const;
	int getHP() const;
	virtual void takeDamage(int);
protected:
	int hit_points;
	std::string type;
	Enemy();
};