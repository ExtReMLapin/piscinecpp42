#include "Sorcerer.hpp"

#include <iostream>

Sorcerer::Sorcerer(void)
{
	// it should'nt happen
}

Sorcerer::Sorcerer(std::string name, std::string title) : name(name), title(title)
{
	std::cout << name << ", " << title << ", is born !" << std::endl; // micro opti mate
}

Sorcerer::~Sorcerer(void)
{ 
	std::cout << name << ", " << title << ", is dead. Consequences will never be the same !" << std::endl; // micro opti mate
}

Sorcerer::Sorcerer(Sorcerer const &source)
{
	*this = source;
	std::cout << name << ", " << title << ", is born !" << std::endl; // micro opti mate

}

Sorcerer & Sorcerer::operator=(const Sorcerer & rhs)
{
	this->name= rhs.name;
	this->title= rhs.title;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Sorcerer &rhs) {
	o << "I am " << rhs.getName() << ", "<< rhs.getTitle() << ", and I like ponies !" << std::endl;;
	return(o);
}

std::string &Sorcerer::getName()
{
	return (this->name);
}

std::string &Sorcerer::getTitle()
{
	return (this->title);
}

void Sorcerer::polymorph(Victim const & victim) const
{
	victim.getPolymorphed();
}

