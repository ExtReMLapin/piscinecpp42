#pragma once

#include <string>
#include "Victim.hpp"

class Sorcerer
{
public:

	Sorcerer(std::string name, std::string title);
	~Sorcerer();
	Sorcerer(const Sorcerer&);
	Sorcerer &operator=(const Sorcerer&);
	std::string &getName();
	std::string &getTitle();
	void polymorph(Victim const &) const;
private:
	Sorcerer();
	std::string name;
	std::string title;
};

std::ostream &operator<<(std::ostream &o, Sorcerer &rhs);