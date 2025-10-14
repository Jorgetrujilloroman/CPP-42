/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:32:20 by jotrujil          #+#    #+#             */
/*   Updated: 2025/10/14 19:17:14 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* brain;
public:
	Cat();
	Cat(const std::string& type);
	~Cat();
	Cat(const Cat& copy);
	Cat& operator= (const Cat& copy);

	void makeSound() const;
	const Brain& getBrain() const;
	Brain& getBrain();
};

#endif