#include "PmergeMe.hpp"
#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>

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

std::vector<int> PmergeMe::generateJacobsthal(int n) {
	std::vector<int> jacob;
	if(n <= 1)
		return jacob;
	
		//J1:
		jacob.push_back(1);
		//J2:
		jacob.push_back(3);

		//We generate it until number is equal or bigger to our list size:
		while (jacob.back() < n) {
			int	next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
			jacob.push_back(next);
		}
		return jacob;
}

std::vector<int>	PmergeMe::fordJohnsonSort(std::vector<int> &v) {
	if (v.size() == 1)
		return v;
	
	int		straggler = -1;
	bool	hasStraggler = false;
	if (v.size() % 2 != 0) {
		straggler = v.back();
		v.pop_back();
		hasStraggler = true;
	}

	std::vector<int>	mainChain;
	std::vector<int>	pend;
	//First we create pairs and separate between bigger or smaller:
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i] > v[i + 1]){
			mainChain.push_back(v[i]);
			pend.push_back(v[i + 1]);
		} else {
			mainChain.push_back(v[i + 1]);
			pend.push_back(v[i]);
		}
	}

	//Use recursive ordenation of the biggers chain:
	mainChain = fordJohnsonSort(mainChain);

	//Optimizate FJ by insrting first Pend element to the beggining b1->a1:
	mainChain.insert(mainChain.begin(), pend[0]);

	//insert the rest of pend using Jacobsthal and binay search:
	//TODO: implement jacobsthal
}	

void	PmergeMe::sortVector(int ac, char **av) {
	clock_t	start = clock();

	_vec.clear();
	for (int i = 0; i < ac; i++)
		_vec.push_back(std::atoi(av[i]));
	
	_vec = fordJohnsonSort(_vec);

	clock_t end = clock();
	double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

	std::cout << "After: ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << (i == _vec.size() - 1 ? "" : " ");
	std::cout << std::endl;
	
	std::cout << "Time to process a range of " << _vec.size() << "elements with std::vector: "
		<< time << " us" << std::endl;
}

void	PmergeMe::sortDeque(int ac, char **av) {
	(void)ac;
	(void)av;
}