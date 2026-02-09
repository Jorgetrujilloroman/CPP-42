#include "PmergeMe.hpp"
#include <iostream>
#include <climits>
#include <cstdlib>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) :
_vec(copy._vec),
_deq(copy._deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
	if (this != &copy) {
		this->_deq = copy._deq;
		this->_vec = copy._vec;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidInput(char **av) {
	for (int i = 1; av[i]; i++) {
		std::string s(av[i]);
		if (s.empty())
			return false;
		for (size_t j = 0; j < s.length(); j++) {
			if (!isdigit(s[j]))
				return false;
		}
		long val = std::atol(av[i]);
		if (val > INT_MAX)
			return false;
	}
	return true;
}

void	PmergeMe::process(int ac, char **av) {
	if (!isValidInput(av)) {
		std::cerr << "Error" << std::endl;
		return;
	}

	std::cout << "Before: ";
	for (int i = 0; i < ac; i++)
		std::cout << av[i] << (i == ac - 1 ? "" : " ");
	std::cout << std::endl;

	this->sortVector(ac, av);
	this->sortDeque(ac, av);
}

void	PmergeMe::sortVector(int ac, char **av) {
	(void)ac;
	(void)av;
}

void	PmergeMe::sortDeque(int ac, char **av) {
	(void)ac;
	(void)av;
}