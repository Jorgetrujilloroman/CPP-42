/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:57:12 by jotrujil          #+#    #+#             */
/*   Updated: 2025/08/01 11:50:21 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
:	_name("Default"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0) {
	std::cout << "Default ClapTrap constructor called \n";
}

ClapTrap::ClapTrap(std::string name) 
:	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0) {
	std::cout << "Claptrap constructor called with name: " << name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap: " << this->_name << " Destructor called\n";
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

void ClapTrap::attack(const std::string& target) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0){
		std::cout << "ClapTrap " << this->_name << " attacks " << target  << ", causing " <<
			this->_attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	} else {
		std::cout << this->_name << " hasn't enough energy or hit points to attack...\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints > 0) {
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		std::cout << this->_name << " was damaged and lost " << amount << " hit points." << std::endl;
		std::cout << _name << " Remain hit points are: " << _hitPoints << std::endl; 
	} else {
		std::cout << this->_name << "can't lose more hit points, because he is death" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints > 0 && this->_hitPoints > 0) {
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << this->_name << " has been repaired, gaining: " << amount << " hit points.  Current HP: "
			<< this->_hitPoints << std::endl;
	} else {
		std::cout << this->_name << " hasn't enough energy or hit points to be repaired..." << std::endl;
	}
}