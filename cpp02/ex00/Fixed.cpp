/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:53:29 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/08 18:56:06 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& copy) : _value(copy._value) {
	std::cout << "Copy constructor called\n";
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