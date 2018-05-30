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

void Human::action(std::string const & action_name, std::string const & target) 
{
	std::string	names[3] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
	void	(Human::*log_funcs[3])(std::string const &target)  = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
	void	(Human::*log_func)(std::string const &target);
	int		ind = 0;
	
	while (ind < 3 && names[ind] != action_name)
		ind++;
	if (ind != 3) // pas trouvé
	{
		log_func = log_funcs[ind];
		(this->*log_func)(target);
	} 
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
