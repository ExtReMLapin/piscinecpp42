#include "Fixed.hpp"
#include <iostream>

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
	this->_raw= rhs.getRawBits();
	return (*this);
}

