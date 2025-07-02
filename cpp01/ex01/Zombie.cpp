/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:27:10 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/02 12:45:36 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {
	std::cout << this->name << " has been destroyed by a headshot!!\n";
}

void	Zombie::setName(const std::string& name) {
	this->name = name;
}

void	Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}