#include "RPN.hpp"
#include <iostream>

RPN::RPN() {}

RPN::RPN(const RPN& copy) :
_container(copy._container) {}

RPN& RPN::operator=(const RPN& copy) {
	if (this != &copy)
		this->_container = copy._container;
	return *this;
}

RPN::~RPN() {}

void	RPN::execute(const std::string &expression) {
	for (size_t i = 0; i < expression.size(); i++){
		if(expression[i] == ' ')
			continue;
		
		if (isdigit(expression[i])) {
			_container.push(expression[i] - '0');
		}
		else if (expression[i] == '+' || expression[i] == '-' ||
		expression[i] == '*' || expression[i] == '/') {
			
			if (_container.size() < 2) {
				std::cerr << "Error" << std::endl;
				return;
			}

			int b = _container.top();
			_container.pop();

			int a = _container.top();
			_container.pop();

			if (expression[i] == '+')
				_container.push(a + b);
			else if (expression[i] == '-')
				_container.push(a - b);
			else if (expression[i] == '*')
				_container.push(a * b);
			else if (expression[i] == '/') {
				if (b == 0) {
					std::cerr << "Error: Division by zero" << std::endl;
					return;
				}
				_container.push(a / b);
			}
		} else {
			std::cerr << "Error" << std::endl;
			return ;
		}
	}

	if (_container.size() != 1) {
			std::cerr << "Error" << std::endl;
		} else {
			std::cout << _container.top() << std::endl;
		}
}