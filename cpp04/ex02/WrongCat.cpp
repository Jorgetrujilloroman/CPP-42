/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:43:42 by jotrujil          #+#    #+#             */
/*   Updated: 2025/09/18 17:15:42 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type = "Wrong Cat";
	std::cout << "A Wrong Cat has appeared!" << std::endl;
}

WrongCat::WrongCat(const std::string& animalType) : WrongAnimal()
{
	this->type = animalType;
	std::cout << "A new Wrong Cat type: " << type << " has appeared!";
}

WrongCat::~WrongCat() {
	std::cout << "This Wrong Cat was destroyed... (No WrongCats were injured)" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal()
{
	type = copy.type;
		std::cout << "Copy constructor called for Wrong Cat" << std::endl;
}

WrongCat& WrongCat::operator= (const WrongCat& copy) {
	if(this != &copy) {
		std::cout << "Wrong Cat copy assignment operator called\n";
		type = copy.type;
	}
	return (*this);
}

// Functions

void	WrongCat::makeSound() const {
	std::cout << "Mahau, Mahau!!... miao :3 !!..." << std::endl;
}