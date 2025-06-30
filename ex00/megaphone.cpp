/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:07:54 by jotrujil          #+#    #+#             */
/*   Updated: 2025/06/30 16:39:49 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	if(argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for(int i = 1; i < argc; i++)
		{
			for(int j = 0; argv[i][j] != '\0'; j++)
				std::cout << (char)std::toupper(argv[i][j]);
		}
		std::cout << std::endl;
	}
	return (0);
}