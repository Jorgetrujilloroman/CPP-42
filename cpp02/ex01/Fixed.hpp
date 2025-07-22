/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:45:55 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/08 19:46:48 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int	_value;
	static const int _fractionalBits = 8;
public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed(const int intNum);
	Fixed(const float floatNum);
	Fixed& operator = (const Fixed& copy);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream	operator<<(std::ostream& os, const Fixed fixed);

#endif