/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:01:56 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/02 14:39:01 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include "iostream"

class HumanB
{
private:
	std::string name;
	Weapon* weapon;
public:
	HumanB(const std::string &name);
	void	setWeapon(Weapon& weapon);
	void	attack();
};

#endif