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

	int getRawBits( void ) const; 
	void setRawBits( int const raw );
	int toInt(void) const;
	float toFloat(void) const;
	bool			operator>(Fixed const & rhs) const;
	bool			operator<(Fixed const & rhs) const;
	bool			operator>=(Fixed const & rhs) const;
	bool			operator<=(Fixed const & rhs) const;
	bool			operator==(Fixed const & rhs) const;
	bool			operator!=(Fixed const & rhs) const;

	Fixed 			&operator=(const Fixed & rhs);
	Fixed 			&operator++(void);
	Fixed			operator+(Fixed const & rhs);
	Fixed			operator-(Fixed const & rhs);
	Fixed			operator*(Fixed const & rhs);
	Fixed			operator/(Fixed const & rhs);

	Fixed			operator++(int);

	static Fixed 	&min(Fixed & val1, Fixed & val2);
	static Fixed 	&max(Fixed & val1, Fixed & val2);

	static Fixed const &min(Fixed const & val1, Fixed const & val2);
	static Fixed const &max(Fixed const & val1, Fixed const & val2);



private:
	static int const _bit;
	int _raw;
};
std::ostream & operator<<(std::ostream & o, Fixed const & rhs);
