/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:13:15 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/03 12:18:56 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {
	Harl harl;
	
	std::cout << "Valid calls: \n";
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	std::cout << "\nInvalid calls: \n";
	harl.complain("NOT-VALID");
	harl.complain("PIÑA");
	harl.complain("42");
	
	return (0);
}