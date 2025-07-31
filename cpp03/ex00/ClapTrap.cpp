/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:57:12 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/31 15:40:49 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name) {
	std::cout << "Claptrap constructor called with name: " << name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called\n";
}
ClapTrap::ClapTrap(const ClapTrap& copy) 
:	_name(copy._name),
	_hitPoints(copy._hitPoints),
	_energyPoints(copy._energyPoints),
	_attackDamage(copy._attackDamage){
		std::cout << "ClapTrap Copy constructor called for " << _name << std::endl;
	}

ClapTrap& ClapTrap::operator= (const ClapTrap& copy) {
	std::cout << "ClapTrap copy assignment operator called\n";
	if (this != &copy) {
		_name = copy._name;
		_hitPoints = copy._hitPoints;
		_energyPoints = copy._energyPoints;
		_attackDamage = copy._attackDamage;
	}
	return (*this);
}