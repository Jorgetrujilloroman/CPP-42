/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:49:29 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/01 17:33:55 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

class PhoneBook
{
private:
	Contact contacts[8];
	int		contactsCount;
	int		oldestIndex;

public:
	PhoneBook();
	void	addContact();
	void	searchContacts() const;
};

#endif