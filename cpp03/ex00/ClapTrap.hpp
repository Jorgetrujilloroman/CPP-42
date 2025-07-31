/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:36:30 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/31 13:04:23 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
private:
	std::string	_name;
	int			_hitPoints = 10;
	int			_energyPoints = 10;
	int			_attackDamage = 0;
public:
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap& copy);
	ClapTrap& operator= (const ClapTrap& copy);
};

#endif