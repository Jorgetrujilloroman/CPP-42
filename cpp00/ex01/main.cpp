/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:05:57 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/22 13:01:11 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
	PhoneBook	PhoneBook;
	std::string command;

	std::cout << "\nWelcome to My Awesome (crappy) PhoneBook!\n\n" ;
	while (true) {
		std::cout << "Enter a command (Caps sensitive): | ADD | SEARCH | EXIT |: ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "ADD")
			PhoneBook.addContact();
		else if (command == "SEARCH")
			PhoneBook.searchContacts();
		else if (command == "EXIT") {
			std::cout << "\nEXITING: All contacts has been removed. Goodbye!\n";
			break ;
		}
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}