/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:40:12 by jotrujil          #+#    #+#             */
/*   Updated: 2025/09/18 16:55:55 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "A generic animal has appeared!" << std::endl;
}

Animal::Animal(const std::string& animalType) : type(animalType) {
	std::cout << "A new animal type: " << type << " has appeared!";
}

Animal::~Animal() {
	std::cout << "This animal was destroyed... (No animals were injured)" << std::endl;
}

Animal::Animal(const Animal& copy) {
	type = copy.type;
		std::cout << "Copy constructor called for type: " << type << std::endl;
}

Animal& Animal::operator= (const Animal& copy) {
	if(this != &copy) {
		std::cout << "Animal copy assignment operator called\n";
		type = copy.type;
	}
	return (*this);
}

// Functions

std::string		Animal::getType() const {
	return type;
}

void	Animal::makeSound() const {
	std::cout << "Ajam Ajam GRR (Generic Animal Sound)..." << std::endl;
}