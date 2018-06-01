#pragma once

#include "Victim.hpp"
#include <string>
class Peon : public Victim
{
public:
	Peon(std::string name);
	virtual ~Peon();
	Peon(const Peon&);
	Peon &operator=(const Peon&);
	virtual void getPolymorphed(void) const;
private:
	Peon();
};