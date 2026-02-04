#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <algorithm>
#include <limits>

class Span {
private:
	unsigned int		_nLimit;
	std::vector<int>	_numbers;
public:
	Span();
	Span(unsigned int N);
	Span(const Span& copy);
	Span& operator=(const Span& copy);
	~Span();

	void	addNumber(int number);
	int		shortestSpan();
	int		longestSpan();

	template <typename T>
	void	addNumbers(T begin, T end){
		if (_numbers.size() + std::distance(begin, end) > _nLimit)
			throw SpanFullException();
		_numbers.insert(_numbers.end(), begin, end);
	}

	class	SpanFullException : public std::exception {
	public:
		virtual const char *what() const throw() { return "Span is full"; }
	};

	class	NoSpanException : public std::exception {
	public:
		virtual const char *what() const throw() { return "Not enough numbers in the Span"; }
	};
};

#endif