#pragma once

#include <string>

class Victim
{
public:
	Victim(std::string name);
	virtual ~Victim();
	Victim(const Victim&);
	Victim &operator=(const Victim&);
	const std::string &getName() const; // compilo de merde
	virtual void getPolymorphed(void) const;

protected:
	std::string name;
	Victim();
};

std::ostream &operator<<(std::ostream &o, Victim &rhs);