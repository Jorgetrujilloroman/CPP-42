
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:57:12 by jotrujil          #+#    #+#             */
/*   Updated: 2025/08/01 11:50:21 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default") {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Default FragTrap constructor called \n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor called with name: " << name << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called for: " << this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
	std::cout << "FragTrap Copy constructor called for " << _name << std::endl;
}

FragTrap& FragTrap::operator= (const FragTrap& copy) {
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
		std::cout << "FragTrap copy assignment operator called\n";
	}
	return (*this);
}

void	FragTrap::attack(const std::string& target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0){
		std::cout << "FragTrap " << this->_name << " screams: 'yells BOOM! KABOOM!' and attacks "
		<< target  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	} else {
		std::cout << this->_name << " hasn't enough energy or hit points to attack...\n";
	}
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_name << " says: 'High five guys! Don't leave me hanging! I'll wait...'" << std::endl;
}