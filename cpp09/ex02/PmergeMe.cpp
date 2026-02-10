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
	for (int i = 1; i < ac; i++)
		std::cout << av[i] << (i == ac - 1 ? "" : " ");
	std::cout << std::endl;

	this->sortVector(ac, av);
	this->sortDeque(ac, av);
}

std::vector<int> PmergeMe::generateJacobsthalVector(int n) {
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

//Same as Vector but for Deque:
std::deque<int> PmergeMe::generateJacobsthalDeque(int n) {
	std::deque<int> jacob;
	if(n <= 1)
		return jacob;
	jacob.push_back(1);
	jacob.push_back(3);

	while (jacob.back() < n) {
		int	next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
		jacob.push_back(next);
	}
	return jacob;
}

std::vector<int>	PmergeMe::fordJohnsonSortVector(std::vector<int> &v) {
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
	for (size_t i = 0; i < v.size(); i += 2) {
		if (v[i] > v[i + 1]){
			mainChain.push_back(v[i]);
			pend.push_back(v[i + 1]);
		} else {
			mainChain.push_back(v[i + 1]);
			pend.push_back(v[i]);
		}
	}

	//Use recursive ordenation of the biggers chain:
	mainChain = fordJohnsonSortVector(mainChain);

	//Optimizate FJ by insrting first Pend element to the beggining b1->a1:
	mainChain.insert(mainChain.begin(), pend[0]);

	//insert the rest of pend using Jacobsthal and binay search:
	std::vector<int>	jacob = generateJacobsthalVector(pend.size());
	size_t				lastInsertedIndex = 1;

	for (size_t j = 1; j < jacob.size(); j++) {
		//Get current Jacob index, limited by pend size:
		size_t	currentJacobIndex = jacob[j];
		if (currentJacobIndex >= pend.size())
			currentJacobIndex = pend.size() - 1;

		// Insert from the JS current index towards back until the last proccessed
		for (size_t k = currentJacobIndex; k >= lastInsertedIndex; k--) {
			std::vector<int>::iterator	it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[k]);
			mainChain.insert(it, pend[k]);
			if (k == lastInsertedIndex)
				break;
		}

		lastInsertedIndex = currentJacobIndex + 1;
		if (lastInsertedIndex >= pend.size())
			break;
	}

	// last step, manage the final straggler 
	if (hasStraggler) {
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(it, straggler);
	}

	return mainChain;
}

// Same as Vector but for Deque:
std::deque<int>	PmergeMe::fordJohnsonSortDeque(std::deque<int> &v) {
	if (v.size() == 1)
		return v;
	int		straggler = -1;
	bool	hasStraggler = false;
	if (v.size() % 2 != 0) {
		straggler = v.back();
		v.pop_back();
		hasStraggler = true;
	}
	std::deque<int>	mainChain;
	std::deque<int>	pend;
	for (size_t i = 0; i < v.size(); i += 2) {
		if (v[i] > v[i + 1]){
			mainChain.push_back(v[i]);
			pend.push_back(v[i + 1]);
		} else {
			mainChain.push_back(v[i + 1]);
			pend.push_back(v[i]);
		}
	}
	mainChain = fordJohnsonSortDeque(mainChain);
	mainChain.insert(mainChain.begin(), pend[0]);
	std::deque<int>	jacob = generateJacobsthalDeque(pend.size());
	size_t				lastInsertedIndex = 1;
	for (size_t j = 1; j < jacob.size(); j++) {
		size_t	currentJacobIndex = jacob[j];
		if (currentJacobIndex >= pend.size())
			currentJacobIndex = pend.size() - 1;
		for (size_t k = currentJacobIndex; k >= lastInsertedIndex; k--) {
			std::deque<int>::iterator	it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[k]);
			mainChain.insert(it, pend[k]);
			if (k == lastInsertedIndex)
				break;
		}
		lastInsertedIndex = currentJacobIndex + 1;
		if (lastInsertedIndex >= pend.size())
			break;
	}
	if (hasStraggler) {
		std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(it, straggler);
	}
	return mainChain;
}	

void	PmergeMe::sortVector(int ac, char **av) {
	clock_t	start = clock();

	_vec.clear();
	for (int i = 1; i < ac; i++)
		_vec.push_back(std::atoi(av[i]));
	
	_vec = fordJohnsonSortVector(_vec);

	clock_t end = clock();
	double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

	std::cout << "After: ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << (i == _vec.size() - 1 ? "" : " ");
	std::cout << std::endl;
	
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector: "
		<< time << " us" << std::endl;
}

void	PmergeMe::sortDeque(int ac, char **av) {
	clock_t	start = clock();

	_vec.clear();
	for (int i = 1; i < ac; i++)
		_deq.push_back(std::atoi(av[i]));
	_deq = fordJohnsonSortDeque(_deq);
	clock_t	end = clock();
	double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
	
	/* std::cout << "After (Deque): ";
	for (size_t i = 0; i < _deq.size(); i++)
		std::cout << _deq[i] << (i == _deq.size() - 1 ? "" : " ");
	std::cout << std::endl; */

	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque: "
		<< time << " us" << std::endl;
}