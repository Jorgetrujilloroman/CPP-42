/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:53:58 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/02 14:25:30 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type) {} 

void	Weapon::setType(const std::string &type) {
	this->type = type;
}

const std::string&	Weapon::getType() const {
	return (this->type);
}