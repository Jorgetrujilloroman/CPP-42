#include "PmergeMe.hpp"
#include <iostream>

int	main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: No input provided." << std::endl;
		return 1;
	}	

	PmergeMe algorithm;
	algorithm.process(ac, av);

	return 0;
}