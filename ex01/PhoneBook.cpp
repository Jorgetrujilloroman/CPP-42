/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:05:47 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/01 17:44:02 by jotrujil         ###   ########.fr       */
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

std::string	formatField(const std::string& str) {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (std::string(10 - str.length(), ' ') + str);
}

void PhoneBook::searchContacts() const {
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|  Index   |First name| Last name| Nickname |" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; i < contactsCount; ++i)
	{
		std::cout << "|" << std::setw(10) << i
		<< "|" << formatField(contacts[i].getFirstName())
		<< "|" << formatField(contacts[i].getLastName())
		<< "|" << formatField(contacts[i].getNickname())
		<< "|" << std::endl
		<< "|-------------------------------------------|" << std::endl;
	}

	if (contactsCount < 1) {
		std::cout << "Your PhoneBook is empty. Use ADD to add a new contact.\n\n";
		return;
	}

	std::string input;
	std::cout << "\nEnter index to display contact information: ";
	std::getline(std::cin, input);

	bool validInput = true;
	if (input.empty())
		validInput = false;
	for (size_t i; i < input.length(); i++)
		if (!isdigit(input[i]))
			validInput = false;

	int index = std::atoi(input.c_str());
	if (!validInput || index < 0 || index >= contactsCount) {
		std::cout << "Invalid index: Please, provide a valid index.\n\n";
		return ;
	}

	std::cout << "DETAILS: \n";
	std::cout << "First Name:     " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name:      " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname:       " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number:   " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << "\n\n";
}