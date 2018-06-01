#include "Victim.hpp"
#include <string>
#include <iostream>

Victim::Victim(void)
{

}

Victim::Victim(std::string name) : name(name)
{
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << this->name <<" just died for no apparent reason !" << std::endl;
}

Victim::Victim(Victim const &source)
{
	*this = source;
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim & Victim::operator=(const Victim & rhs)
{
	this->name= rhs.name;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Victim &rhs) {
	o << "I'm " << rhs.getName() << " and I like otters !" << std::endl;
	return(o);
}

std::string const &Victim::getName() const
{
	return (this->name);
}

void Victim::getPolymorphed(void) const
{
	std::cout << this->getName() << " has been turned into a cute little sheep !" << std::endl;
}
