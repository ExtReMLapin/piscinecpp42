#include "Human.hpp"

#include <string>
#include <iostream>
#include <map>

Human::Human(void)
{

}

Human::~Human(void)
{

}

typedef void(Human::*humanMethodCall)(std::string const &); // le std::string const c'est pas le nom mais le target

void Human::action(std::string const & action_name, std::string const & target) 
{
	// http://www.cplusplus.com/reference/map/map/
	// https://stackoverflow.com/questions/19473313/how-to-call-a-function-by-its-name-stdstring-in-c


	std::map<std::string, humanMethodCall> myMap;
	myMap["meleeAttack"] = &Human::meleeAttack;
    myMap["rangedAttack"] = &Human::rangedAttack;
	myMap["intimidatingShout"] = &Human::intimidatingShout;

	if ((myMap.count(action_name)) == 0)
	{
		std::cout << "attempt to call method : " << action_name << " which is invalid" << std::endl;
		return;
	}

	humanMethodCall call = myMap[action_name];
	(this->*call)(target);
}


void Human::meleeAttack(std::string const & target)
{
	std::cout << "Used your fists to punch " << target << std::endl;
}


void Human::rangedAttack(std::string const & target)
{
	std::cout << "Used a bow to attack " << target << std::endl;
}


void Human::intimidatingShout(std::string const & target)
{
	std::cout << "Yelled : REEEEEEEEEEEEEEEEEEEEEEEEEE at " << target << " but he seems more confused than injuried" << std::endl;
}

