#pragma once

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(Fixed const &source);
	Fixed & operator=(const Fixed & rhs);
	int getRawBits( void ) const; 
	void setRawBits( int const raw );
private:
	static int const _bit;
	int _raw;
};