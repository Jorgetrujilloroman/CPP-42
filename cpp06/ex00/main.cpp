/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:11:04 by jotrujil          #+#    #+#             */
/*   Updated: 2025/11/13 17:19:02 by jotrujil         ###   ########.fr       */
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

/* 

Polemic tests:

./convert 2147483648
./convert -2147483649
./convert 1.8e308
./convert 300
./convert nanf
./convert -inf
./convert +inff
./convert 99.99999
./convert -0.5
./convert -0.0f
./convert '@'
./convert 7
./convert 32
./convert 42a
./convert 42f.0
./convert 1.0.0 

*/