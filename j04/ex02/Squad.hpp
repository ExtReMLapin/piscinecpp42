#pragma once


#include "ISquad.hpp"

class Squad : public ISquad
{
typedef struct s_list
{
	ISpaceMarine	*instance;
	s_list			*next;
}				t_list;

public:

	Squad( void );
	Squad( Squad const & src );
	~Squad( void );
	Squad& operator=(Squad const & rhs);

	int		getCount() const;
	ISpaceMarine*	getUnit( int index ) const;
	int		push( ISpaceMarine* sm );
	

private:
	int		n;
	t_list	*list;
};