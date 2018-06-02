
#include "Squad.hpp"
#include <iostream>

Squad::Squad( void )
{
	this->list = NULL;
	this->n = 0;
}

Squad::Squad( Squad const & src )
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = this->list;
	tmp2 = src.list;
	this->list = new(t_list); // pas droit d'utiliser malloc
	this->list->data = tmp2->data;
	this->list->next = NULL;
	tmp2 = tmp2->next;
	while (tmp2)
	{
		tmp = this->list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new(t_list);
		tmp->next->data = tmp2->data;
		tmp->next->next = NULL;
		tmp2 = tmp2->next;
	}
	this->n = src.n; // sans oublier le nombre
}

Squad::~Squad( void )
{
	t_list	*tmp;

	while (this->list)
	{
		tmp = this->list;
		delete this->list->data;
		this->list = this->list->next;
		delete tmp;
	}
}

int		Squad::getCount( void ) const
{
	return n;
}

int		Squad::push( ISpaceMarine* sm )
{
	t_list	*tmp;

	if (sm == NULL)
		return (this->n); // bon ils sont pas méga clair dans la consigne donc bon
	if (this->list == NULL)
	{
		this->list = new(t_list);
		this->list->data = sm;
		this->list->next = NULL;
	}
	else
	{
		tmp = this->list;
		while (tmp->next)
		{
			if (tmp->data == sm)
				return (n); // bein ui il est déja dedans consigne pas méga clair si on doit faire de la merde ou ca
			tmp = tmp->next;
		}
		tmp->next = new(t_list);
		tmp->next->data = sm;
		tmp->next->next = NULL;
	}
	return (++n);
}

ISpaceMarine*	Squad::getUnit( int index ) const
{
	t_list	*tmp;

	tmp = this->list;
	while (index != 0 && tmp)
	{
		tmp = tmp->next;
		index--;
	}
	return (tmp->data);
}

Squad&  Squad::operator=(Squad const & rhs)
{
    t_list  *tmp;

    tmp= this->list;
	while (this->list) // comme au destructeur sinon fuite de mémoire
	{
		tmp = this->list;
		delete this->list->data;
		this->list = this->list->next; // delete le current et colle le suivant au start
		delete tmp; // delete liste sinon fuite de mémoire
	}

	t_list	*tmp2;


	/*
	** On pourais ne pas delete les strucs et ecrire par dessus puis allouer ce
	** qui manque ou delete ce qu'il y a en trop mais je suis fatigué et le piscine
	** c++ est longue merci et aurevoir
	*/

	tmp2 = rhs.list;
	this->list = new(t_list);
	this->list->data = tmp2->data;
	this->list->next = NULL;
	tmp2 = tmp2->next;
	tmp = this->list;
	while (tmp2)
	{
		tmp = this->list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new(t_list);
		tmp->next->data = tmp2->data;
		tmp->next->next = NULL;
		tmp2 = tmp2->next;
	}
	this->n = rhs.n;
    return *this;
}