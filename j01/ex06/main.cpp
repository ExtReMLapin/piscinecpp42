
#include "HumanB.hpp"
#include "HumanA.hpp"
#include <string>
#include "Weapon.hpp"
#include <iostream>




int main()
{

		Weapon *club = new Weapon("crude spiked club");
		HumanA bob("Bob", *club);
		bob.attack();
		club->setType("some other type of club");
		delete club;
		bob.attack();

}