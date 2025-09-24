/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:43:42 by jotrujil          #+#    #+#             */
/*   Updated: 2025/09/24 14:20:00 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "A Dog has appeared!" << std::endl;
	brain = new Brain;
}

Dog::Dog(const std::string& animalType) : Animal()
{
	this->type = animalType;
	std::cout << "A new dog type: " << type << " has appeared!";
}

Dog::~Dog() {
	std::cout << "This Dog was destroyed... (No Dogs were injured)" << std::endl;
	delete brain;
}

Dog::Dog(const Dog& copy) : Animal()
{
	type = copy.type;
		std::cout << "Copy constructor called for Dog" << std::endl;
}

Dog& Dog::operator= (const Dog& copy) {
	if(this != &copy) {
		std::cout << "Dog copy assignment operator called\n";
		type = copy.type;
	}
	return (*this);
}

// Functions

void	Dog::makeSound() const {
	std::cout << "Guau, Guay!!... GRRRRR!!..." << std::endl;
}