#pragma once

#include <string>

class Zombie
{
public:
	Zombie(std::string name, std::string type);
	~Zombie(void);
	void announce(void) const;
private:
	std::string type;
	std::string name;


};