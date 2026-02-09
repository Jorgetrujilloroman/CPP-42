#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>

class PmergeMe {
private:
	/* Chosen vector for its contiguous memory and fast random access, 
	and deque for its efficient memory management in large sequences, 
	satisfying the two-container requirement. */
	std::vector<int>	_vec;
	std::deque<int>		_deq;

	bool				isValidInput (char **av);
	std::vector<int>	generateJacobsthal(int n);
	std::vector<int>	fordJohnsonSort(std::vector<int> &vector);
public:
	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& copy);
	~PmergeMe();

	void	process(int ac, char **av);
	void	sortVector(int ac, char **av);
	void	sortDeque(int ac, char **av);
};

#endif