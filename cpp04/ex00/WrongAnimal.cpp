/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:40:12 by jotrujil          #+#    #+#             */
/*   Updated: 2025/09/18 16:55:55 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "A generic WrongAnimal has appeared!" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& WrongAnimalType) : type(WrongAnimalType) {
	std::cout << "A new WrongAnimal type: " << type << " has appeared!";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "This WrongAnimal was destroyed... (No WrongAnimals were injured)" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	type = copy.type;
		std::cout << "Copy constructor called for type: " << type << std::endl;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& copy) {
	if(this != &copy) {
		std::cout << "WrongAnimal copy assignment operator called\n";
		type = copy.type;
	}
	return (*this);
}

// Functions

std::string	WrongAnimal::getType() const {
	return type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "Ahia Ahia GRR (Generic Wrong Animal Sound)..." << std::endl;
}