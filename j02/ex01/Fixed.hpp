#pragma once
#include <iostream>

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(Fixed const &source);
	Fixed(int const n);
	Fixed(float const n);
	Fixed & operator=(const Fixed & rhs);
	int getRawBits( void ) const; 
	void setRawBits( int const raw );
	int toInt(void) const;
	float toFloat(void) const;

private:
	static int const _bit;
	int _raw;
};
std::ostream & operator<<(std::ostream & o, Fixed const & rhs);
