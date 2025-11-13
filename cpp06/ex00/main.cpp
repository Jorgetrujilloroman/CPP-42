/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:11:04 by jotrujil          #+#    #+#             */
/*   Updated: 2025/11/13 13:16:13 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Invalid number of args. Correct usage: ./convert <literal_value>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}