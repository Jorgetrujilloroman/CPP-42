/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:43:42 by jotrujil          #+#    #+#             */
/*   Updated: 2025/10/14 19:13:37 by jotrujil         ###   ########.fr       */
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
	delete brain;
	std::cout << "This Dog was destroyed... (No Dogs were injured)" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Copy constructor called for Dog" << std::endl;
	type = copy.type;
	brain = new Brain(*copy.brain);

}

Dog& Dog::operator= (const Dog& copy) {
	if(this != &copy) {
		std::cout << "Dog copy assignment operator called\n";
		Animal::operator=(copy);
		delete brain;
		brain = new Brain(*copy.brain);
	}
	return (*this);
}

// Functions

void	Dog::makeSound() const {
	std::cout << "Guau, Guay!!... GRRRRR!!..." << std::endl;
}

// Only for reading
const Brain& Dog::getBrain() const {
	return *brain;
}

// For modifying it
Brain& Dog::getBrain() {
	return *brain;
}