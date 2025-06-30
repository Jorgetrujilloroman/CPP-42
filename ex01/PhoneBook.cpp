/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:05:47 by jotrujil          #+#    #+#             */
/*   Updated: 2025/06/30 18:54:55 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactsCount(0), oldestIndex(0) {}

void	PhoneBook::addContact() {
	Contact 	newContact;
	std::string	input;

	do	{
		std::cout << "First name: ";
		std::getline(std::cin, input);
	} while(input.empty());
	newContact.setFirstName(input);
	do	{
		std::cout << "Last name: ";
		std::getline(std::cin, input);
	} while(input.empty());
	newContact.setLastName(input);
	do	{
		std::cout << "Nickname: ";
		std::getline(std::cin, input);
	} while(input.empty());
	newContact.setNickname(input);
	do	{
		std::cout << "Phone number: ";
		std::getline(std::cin, input);
	} while(input.empty());
	newContact.setPhoneNumber(input);
	do	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, input);
	} while(input.empty());
	newContact.setDarkestSecret(input);

	if (contactsCount < 8) {
		contacts[contactsCount] = newContact;
		contactsCount++;
	} else {
		contacts[oldestIndex] = newContact;
		oldestIndex = (oldestIndex + 1) % 8;
	}
}

void PhoneBook::searchContacts() const {
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|  Index   | First name| Last name| Nickname |" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	for (int i = 0; i < contactsCount; ++i)
	{
		std::cout << "|" << std::endl;
		std::cout << "----------------------------------------------" << std::endl;
	}
}