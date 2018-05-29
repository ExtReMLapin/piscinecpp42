#include "Human.hpp"


int		main()
{
	Human	_;

	_.action("meleeAttack", "Sam");
	_.action("rangedAttack", "Alex");
	_.action("intimidatingShout", "Clover");


	_.action("LIBEREZ LE TIBET", "Clover"); // segfault check
}