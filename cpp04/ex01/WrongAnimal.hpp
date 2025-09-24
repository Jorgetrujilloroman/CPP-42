/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:26:12 by jotrujil          #+#    #+#             */
/*   Updated: 2025/09/18 17:31:40 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const std::string& type);
	~WrongAnimal();
	WrongAnimal(const WrongAnimal& copy);
	WrongAnimal& operator= (const WrongAnimal& copy);

	// Functions
	std::string getType() const;
	void	makeSound() const;
};

#endif