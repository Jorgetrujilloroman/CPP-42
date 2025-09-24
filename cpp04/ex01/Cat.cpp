/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:43:42 by jotrujil          #+#    #+#             */
/*   Updated: 2025/09/18 17:15:42 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "A Cat has appeared!" << std::endl;
}

Cat::Cat(const std::string& animalType) : Animal()
{
	this->type = animalType;
	std::cout << "A new Cat type: " << type << " has appeared!";
}

Cat::~Cat() {
	std::cout << "This Cat was destroyed... (No Cats were injured)" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal()
{
	type = copy.type;
		std::cout << "Copy constructor called for Cat" << std::endl;
}

Cat& Cat::operator= (const Cat& copy) {
	if(this != &copy) {
		std::cout << "Cat copy assignment operator called\n";
		type = copy.type;
	}
	return (*this);
}

// Functions

void	Cat::makeSound() const {
	std::cout << "Miau, Miaaaaau!!... miau :3 !!..." << std::endl;
}