/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:40:12 by jotrujil          #+#    #+#             */
/*   Updated: 2025/09/18 16:55:55 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "A generic Brain has appeared!" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
}

Brain::~Brain() {
	std::cout << "This Brain was destroyed... (No more ideas are coming)" << std::endl;
}

Brain::Brain(const Brain& copy) {
		std::cout << "Copy constructor called for Brain" << std::endl;
		for (int i = 0; i < 100; i++)
			ideas[i] = copy.ideas[i];
}

Brain& Brain::operator= (const Brain& copy) {
	if(this != &copy) {
		std::cout << "Brain copy assignment operator called\n";
		for (int i = 0; i < 100; i++)
			ideas[i] = copy.ideas[i];
	}
	return (*this);
}

std::string	Brain::getIdea(int index) const
{
	return this->ideas[index];
}

void		Brain::setIdea(int index, const std::string& idea)
{
	this->ideas[index] = idea;
}