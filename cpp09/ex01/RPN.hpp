#ifndef RPNH_HPP
#define RPNH_HPP

#include <string>
#include <stack>

class RPN {
private:
	// Selected stack because RPN requires LIFO (Last-In-First-Out) to process operands.
	std::stack<int>	_container;

public:
	RPN();
	RPN(const RPN& copy);
	RPN& operator=(const RPN& copy);
	~RPN();

	void	execute(const std::string &expression);
};


#endif