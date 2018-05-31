#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_bit = 8;

Fixed::Fixed() : _raw(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &source)
{
	//std::cout << "Copy constructor called" << std::endl; 
	*this = source;
}


Fixed::Fixed(int const n)
{
	//std::cout << "Int constructor called" << std::endl;
	setRawBits(n << this->_bit); // on bouge l'int à gauche de la virgule fixe
}

Fixed::Fixed(float const n)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_raw = roundf(n * (1 << this->_bit)); // on peut pas juste décaler vue c'est une float, bon on perd de la précision là par contre
	return;
}

int		Fixed::toInt(void) const{
	return (this->_raw >> this->_bit); // bah on fait l'inverse quoi
}

float	Fixed::toFloat(void) const{
	return ((float)this->_raw / (1 << this->_bit)); // pareil, on fait l'inverse
}

int 	Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

void 	Fixed::setRawBits( int const raw )
{
	this->_raw = raw;
}




std::ostream &operator<<(std::ostream &o, Fixed const &rhs) {
	o << rhs.toFloat();
	return(o);
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	//std::cout << "Assignation operator called" << std::endl;
	this->_raw = rhs._raw;
	return (*this);
}


bool		Fixed::operator>(Fixed const & rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool		Fixed::operator<(Fixed const & rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool		Fixed::operator>=(Fixed const & rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool		Fixed::operator<=(Fixed const & rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool		Fixed::operator==(Fixed const & rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool		Fixed::operator!=(Fixed const & rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}


Fixed 		&Fixed::operator++(void)
{
	this->_raw++;
	return (*this);
}


Fixed 		&Fixed::operator--(void)
{
	this->_raw--;
	return (*this);
}

/*
** gros hack, on peut pas dire "attends une instruction avant de faire ce que t'as à faire"
** donc on modifie ce quon doit modifier mais on retourne une copie de la valeur d'avant.
*/ 

Fixed		Fixed::operator++(int) 
{
	Fixed	groshack;

	groshack = *this; // copie implicide
	this->_raw++;
	return (groshack);
}

Fixed 		Fixed::operator--(int)
{
	Fixed	groshack;

	groshack = *this;
	this->_raw--;
	return (groshack);
}


Fixed		Fixed::operator+(Fixed const & rhs)
{
	Fixed output;
	output._raw = this->_raw + rhs._raw;
	return (output);
}


Fixed		Fixed::operator-(Fixed const & rhs)
{
	Fixed output;
	output._raw = this->_raw - rhs._raw; // pas compliqué
	return (output);
}

Fixed		Fixed::operator*(Fixed const & rhs)
{
	Fixed output;
	//output._raw =  ((this->_raw >> this->_bit) * (rhs._raw >> this->_bit)) << this->_bit ; // perde de precision donc on oublie ca
	output._raw = (this->_raw * rhs._raw) >> this->_bit;
	return (output);
}

Fixed		Fixed::operator/(Fixed const & rhs)
{
	Fixed output;
	output._raw =  (this->_raw / rhs._raw) >> this->_bit; // pareil
	return (output);
}



Fixed 	&Fixed::min(Fixed & val1, Fixed & val2)
{
	if (val1._raw < val2._raw)
		return (val1);
	return (val2);
}

Fixed 	&Fixed::max(Fixed & val1, Fixed & val2)
{
	if (val1._raw > val2._raw)
		return (val1);
	return (val2);
}

Fixed const &Fixed::min(Fixed const & val1, Fixed const & val2)
{
	if (val1._raw < val2._raw)
		return (val1);
	return (val2);
}

Fixed const &Fixed::max(Fixed const & val1, Fixed const & val2)
{
	if (val1._raw > val2._raw)
		return (val1);
	return (val2);
}


