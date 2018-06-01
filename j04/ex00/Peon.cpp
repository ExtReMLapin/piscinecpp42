#include "Peon.hpp"

#include <string>
#include <iostream>

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(Peon const &source)
{
	*this = source;
	std::cout << "Zog zog." << std::endl;
}

Peon & Peon::operator=(const Peon & rhs)
{
	this->name= rhs.name;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Peon &rhs) {
	o << "I'm " << rhs.getName() << " and I like otters !" << std::endl;
	return(o);
}

void Peon::getPolymorphed(void) const
{
	std::cout << this->getName() << " has been turned into a pink pony !" << std::endl;
}
