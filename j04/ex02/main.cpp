#include "ISpaceMarine.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "Squad.hpp"
#include "ISquad.hpp"
#include <iostream>

int main(void)
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
	ISpaceMarine* cur = vlc->getUnit(i);
	cur->battleCry();
	cur->rangedAttack();
	cur->meleeAttack();
	}


	

	TacticalMarine* ism = new TacticalMarine();
	ISpaceMarine* tcm = new TacticalMarine(*ism);
	tcm = jim; // et bam on transforme un tactical marine en assault terminator, merci l'interface
	tcm->battleCry();
	tcm->rangedAttack();
	tcm->meleeAttack();

	return 0;
}