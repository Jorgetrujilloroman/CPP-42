/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:53:29 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/29 20:48:29 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	//std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& copy) : _value(copy._value) {
	//std::cout << "Copy constructor called\n";
}

/* Left shift by 8 to convert int to fixed point*/
Fixed::Fixed(const int intNum) {
	//std::cout << "Int constructor called\n";
	this->_value = intNum << Fixed::_fractionalBits;
}

/* scale the float by 2⁸, round to fix floating-point errors, and cast it to int for storage */
Fixed::Fixed(const float floatNum) {
	//std::cout << "Float constructor called\n";
	this->_value = static_cast<int>(roundf(floatNum * (1 << Fixed::_fractionalBits)));
}

Fixed& Fixed::operator = (const Fixed& copy){
	//std::cout << "Copy assignment operator called\n";
	if (this != &copy)
		this->_value = copy._value;
	return (*this);
}

Fixed::~Fixed(){
	//std::cout << "Destructor called\n";
}

int		Fixed::getRawBits( void ) const {
	//std::cout << "getRawBits member function called\n";
	return (this->_value);
}

void	Fixed::setRawBits( int const raw ){
	this->_value = raw;
}

float	Fixed::toFloat( void ) const {
	return (static_cast<float>(_value) / (1 << Fixed::_fractionalBits));
}

int		Fixed::toInt( void ) const {
	return (_value >> Fixed::_fractionalBits);
}

 /* Print Fixed objects by converting them to float. */
std::ostream&	operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}

/* Comparison */
bool	Fixed::operator>(const Fixed& other) const {
	return (this->_value > other._value);
}

bool	Fixed::operator<(const Fixed& other) const {
	return (this->_value < other._value);
}

bool	Fixed::operator>=(const Fixed& other) const {
	return (this->_value >= other._value);
}

bool	Fixed::operator<=(const Fixed& other) const {
	return (this->_value <= other._value);
}

bool	Fixed::operator==(const Fixed& other) const {
	return (this->_value == other._value);
}

bool	Fixed::operator!=(const Fixed& other) const {
	return (this->_value != other._value);
}

/* Arithmetic */
Fixed	Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_value + other._value);
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_value - other._value);
	return (result);
}

// I am using long here to avoid int * int causing overflow
Fixed	Fixed::operator*(const Fixed& other) const {
	Fixed result;
	long	rawMult = static_cast<long>(this->_value) * static_cast<long>(other._value);
	result.setRawBits(static_cast<int>(rawMult >> Fixed::_fractionalBits));
	return (result);
}

// Managing also division by 0, returning max int.
Fixed	Fixed::operator/(const Fixed& other) const {
	Fixed result;
	if (other._value == 0) {
		std::cout << "Error: Division by zero -> Returning Max Int: 2147483647\n";
		result.setRawBits(INT_MAX);
		return (result);
	} else {
		long scaledValue = static_cast<long>(this->_value) << Fixed::_fractionalBits;
		result.setRawBits(static_cast<int>(scaledValue / other._value));
		return (result);
	}
}

Fixed	Fixed::operator++() {
	this->_value += (1 << Fixed::_fractionalBits);
	return *(this);
}

Fixed	Fixed::operator++(int) {
	Fixed temp(*this);
	this->_value += (1 << Fixed::_fractionalBits);
	return (temp);
}

Fixed	Fixed::operator--() {
	this->_value -= (1 << Fixed::_fractionalBits);
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed temp(*this);
	this->_value -= (1 << Fixed::_fractionalBits);
	return (temp);
}

// Using ternary operator: condition ? value_if_true : value_if_false
Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}