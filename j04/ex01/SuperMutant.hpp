#pragma once

#include "Enemy.hpp"

class SuperMutant
{
public:
	SuperMutant();
	~SuperMutant();
	SuperMutant(SuperMutant const & src);
	SuperMutant &	operator=(SuperMutant const & rhs);	
};