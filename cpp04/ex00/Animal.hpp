/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:26:12 by jotrujil          #+#    #+#             */
/*   Updated: 2025/08/05 19:56:30 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(const std::string& type);
	virtual ~Animal();
	Animal(const Animal& copy);
	Animal& operator= (const Animal& copy);

	// Functions
	std::string		getType() const;
	virtual void	makeSound() const;
};

#endif