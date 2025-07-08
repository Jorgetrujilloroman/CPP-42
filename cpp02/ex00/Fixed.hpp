/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:45:55 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/08 18:16:35 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	_value;
	static const int _fractionalBits = 8;
public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed& operator = (const Fixed& copy);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif