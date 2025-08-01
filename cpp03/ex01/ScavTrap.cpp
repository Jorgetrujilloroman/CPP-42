/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:39:38 by jotrujil          #+#    #+#             */
/*   Updated: 2025/08/01 18:19:32 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:57:12 by jotrujil          #+#    #+#             */
/*   Updated: 2025/08/01 11:50:21 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default") {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Default ScavTrap constructor called \n";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor called with name: " << name << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called for: " << this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
	std::cout << "ScavTrap Copy constructor called for " << _name << std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap& copy) {
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
		std::cout << "ScavTrap copy assignment operator called\n";
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0){
		std::cout << "ScavTrap " << this->_name << " screams 'THIS TIME IT'LL BE AWESOME!' and attacks to "
		<< target  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	} else {
		std::cout << this->_name << " hasn't enough energy or hit points to attack...\n";
	}
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper Mode!" << std::endl; 
}