/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:06:16 by jotrujil          #+#    #+#             */
/*   Updated: 2025/06/30 17:48:00 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

void	Contact::setFirstName(const std::string& value)
{
	firstName = value;
}

void	Contact::setLastName(const std::string& value)
{
	lastName = value;
}

void	Contact::setNickname(const std::string& value)
{
	nickname = value;
}

void	Contact::setPhoneNumber(const std::string& value)
{
	phoneNumber = value;
}

void	Contact::setDarkestSecret(const std::string& value)
{
	darkestSecret = value;
}

std::string Contact::getFirstName() const
{
	return firstName;
}

std::string Contact::getLastName() const
{
	return lastName;
}

std::string Contact::getNickname() const
{
	return nickname;
}

std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}