/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:26:12 by jotrujil          #+#    #+#             */
/*   Updated: 2025/09/18 17:15:40 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
protected:
	std::string type;

public:
	AAnimal();
	AAnimal(const std::string& type);
	virtual ~AAnimal();
	AAnimal(const AAnimal& copy);
	AAnimal& operator= (const AAnimal& copy);

	// Functions
	std::string		getType() const;
	virtual void	makeSound() const = 0;
};

#endif