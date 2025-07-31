/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:26:54 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/31 18:39:13 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main ( void ) {
	ClapTrap Trappy;
	ClapTrap Clappy("Clappy");

	Clappy.attack("Trappy");
	Clappy.attack("Himself");
	Clappy.takeDamage(5);
	Clappy.beRepaired(3);
	Clappy.attack("Himself again");
	Clappy.takeDamage(20);	
}