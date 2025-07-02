/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:11:54 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/02 13:01:02 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int N = 10;
	Zombie* horde = zombieHorde(N, "Joaquin");
	
	for (int i = 0; i < N; i++){
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}