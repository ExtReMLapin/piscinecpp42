#pragma once

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{

public:
	AssaultTerminator( void );
	AssaultTerminator( AssaultTerminator const & src );
	~AssaultTerminator( void );
	void	battleCry() const;
	void	rangedAttack() const;
	void	meleeAttack() const;
	ISpaceMarine* clone( void ) const;

	AssaultTerminator& operator=(AssaultTerminator const & rhs);
};
