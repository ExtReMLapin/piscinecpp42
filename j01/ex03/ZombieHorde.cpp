#include "ZombieHorde.hpp"
#include "Zombie.hpp"

ZombieHorde::ZombieHorde(int N)
{
	if (N < 1)
		return;
	std::string		tab[] = {"Roger", "Ben", "Laden", "Yabonanenebanana", "goulalibi"};
	this->list = new Zombie[N];
	this->len = N;

	int i = 0;
	while (i < len)
		this->list[i++].name = tab[rand() % 5];		
}


ZombieHorde::~ZombieHorde(void)
{
	delete [] list;
}

void ZombieHorde::announce(void)
{
	int i = 0;
	while (i < this->len)
		this->list[i++].announce();

}