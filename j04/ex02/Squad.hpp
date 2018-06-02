#pragma once


#include "ISquad.hpp"



class Squad : public ISquad
{
	struct t_list
	{
		ISpaceMarine	*data;
		t_list			*next;
	};
	public:
		~Squad( void );
		int		getCount() const;
		ISpaceMarine*	getUnit( int index ) const;
		int		push( ISpaceMarine* sm );

		Squad( void );
		Squad( Squad const & src );
		Squad& operator=(Squad const & rhs);
	private:

		int		n;
		t_list	*list;
};