#pragma once

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{

public:
	TacticalMarine( void );
	TacticalMarine( TacticalMarine const & src );
	~TacticalMarine( void );
	void	battleCry() const;
	void	rangedAttack() const;
	void	meleeAttack() const;
	ISpaceMarine* clone( void ) const;

	TacticalMarine& operator=(TacticalMarine const & rhs);
};
