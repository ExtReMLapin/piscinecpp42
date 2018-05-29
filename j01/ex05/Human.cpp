#include "Human.hpp"
#include <string>

Human::Human(void)
{

}

Human::~Human(void)
{
	
}

std::string Human::identify() const
{
	return (this->brain.identify());
}


Brain &Human::getBrain()
{
	return (this->brain);
}
