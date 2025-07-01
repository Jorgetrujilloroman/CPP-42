/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:27:10 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/01 21:00:08 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie(){
	std::cout << this->name << "has been destroyed by a headshot!!\n";
}

void	Zombie::announce(){
	std::cout << this->name << " BraiiiiiiinnnzzzZ...\n";
}