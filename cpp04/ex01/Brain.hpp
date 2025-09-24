/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:23:12 by jotrujil          #+#    #+#             */
/*   Updated: 2025/09/24 14:00:32 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HH
#define BRAIN_HH

#include <string>
#include <iostream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain& copy);
	Brain& operator= (const Brain& copy);
	~Brain();

	std::string	getIdea(int index) const;
	void		setIdea(int index, const std::string& idea);
};

#endif