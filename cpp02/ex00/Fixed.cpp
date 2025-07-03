/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:53:29 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/03 17:08:10 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed& copy) : _value(copy._value) {}

Fixed& Fixed::operator = (const Fixed& copy){
	if (this != &copy)
		this->_value = copy._value;
	return (*this);
}

Fixed::~Fixed()
{
}