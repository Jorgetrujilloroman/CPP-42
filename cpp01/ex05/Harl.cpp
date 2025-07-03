/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:41:23 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/03 12:19:36 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void ) {
	std::cout << "- I love having pineapple in my extra-cheessy-large-tasty pizza."
		"I don't know why people do hate pineapple on pizza...\n";
}

void Harl::info( void ) {
	std::cout << "- I cannot believe adding extra pineapple costs more money. You didn’t put "
		"enough pineapple in my pizza! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning( void ) {
	std::cout << "- I think I deserve to have some extra pineapple for free. I’ve been coming for "
		"years, whereas you started working here just last month.\n";
}

void Harl::error( void ) {
	std::cout << "- This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain( std::string level ) {
	
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	HarlComplain funcs[4] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*funcs[i])();
			return ;
		}
	}
	std::cout << "Complain level not found. Please, introduce a valid level: "
				"DEBUG, INFO, WARNING, ERROR\n";
	return ;
}