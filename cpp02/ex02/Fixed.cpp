/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:53:29 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/22 18:42:17 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& copy) : _value(copy._value) {
	std::cout << "Copy constructor called\n";
}

/* Left shift by 8 to convert int to fixed point*/
Fixed::Fixed(const int intNum) {
	std::cout << "Int constructor called\n";
	this->_value = intNum << _fractionalBits;
}

/* scale the float by 2⁸, round to fix floating-point errors, and cast it to int for storage */
Fixed::Fixed(const float floatNum) {
	std::cout << "Float constructor called\n";
	this->_value = static_cast<int>(roundf(floatNum * (1 << _fractionalBits)));
}

Fixed& Fixed::operator = (const Fixed& copy){
	std::cout << "Copy assignment operator called\n";
	if (this != &copy)
		this->_value = copy._value;
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return (this->_value);
}

void	Fixed::setRawBits( int const raw ){
	this->_value = raw;
}

float	Fixed::toFloat( void ) const {
	return (static_cast<float>(_value) / (1 << _fractionalBits));
}

int		Fixed::toInt( void ) const {
	return (_value >> _fractionalBits);
}

 /* Print Fixed objects by converting them to float. */
std::ostream&	operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}