#pragma once

#include <string>
#include "Brain.hpp"

class Human
{
public:
	Human();
	~Human();
	Brain &getBrain();
	std::string identify() const;
private:
	Brain brain;
};