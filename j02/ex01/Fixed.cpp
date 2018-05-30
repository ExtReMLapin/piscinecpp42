#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_bit = 8;

Fixed::Fixed() : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &source)
{
	std::cout << "Copy constructor called" << std::endl; 
	*this = source;
}


Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(n << this->_bit); // on bouge l'int à gauche de la virgule fixe
}

Fixed::Fixed(float const n)
{
	std::cout << "Float constructor called" << std::endl;
	this->_raw = roundf(n * (1 << this->_bit));
	return;
}

int		Fixed::toInt(void) const{
	return (this->_raw >> this->_bit); // bah on fait l'inverse quoi
}

float	Fixed::toFloat(void) const{
	return ((float)this->_raw / (1 << this->_bit)); // pareil, on fait l'inverse
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

void Fixed::setRawBits( int const raw )
{
	this->_raw = raw;
}


Fixed & Fixed::operator=(const Fixed & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_raw= rhs._raw;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs) {
	o << rhs.toFloat();
	return(o);
}
