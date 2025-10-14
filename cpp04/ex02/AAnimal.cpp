/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:40:12 by jotrujil          #+#    #+#             */
/*   Updated: 2025/09/18 16:55:55 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal") {
	std::cout << "A generic Animal has appeared!" << std::endl;
}

AAnimal::AAnimal(const std::string& AAnimalType) : type(AAnimalType) {
	std::cout << "A new Animal type: " << type << " has appeared!" << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "This Animal was destroyed... (No Animals were injured)" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) : type(copy.type) {
	std::cout << "Copy constructor called for type: " << type << std::endl;
}

AAnimal& AAnimal::operator= (const AAnimal& copy) {
	if(this != &copy) {
		std::cout << "Animal copy assignment operator called\n";
		type = copy.type;
	}
	return (*this);
}

// Functions

std::string		AAnimal::getType() const {
	return type;
}