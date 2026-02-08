#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av){
	if (ac != 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	RPN calculator;
	calculator.execute(av[1]);

	return 0;
}
