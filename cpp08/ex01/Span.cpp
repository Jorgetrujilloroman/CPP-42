	#include "Span.hpp"
	
Span::Span() :
	_nLimit(0)  {}

Span::Span(unsigned int N) :
	_nLimit(N) {}

Span::Span(const Span& copy) :
	_nLimit(copy._nLimit),
	_numbers(copy._numbers) {}

Span& Span::operator=(const Span& copy) {
	if (this != &copy) {
		this->_nLimit = copy._nLimit;
		this->_numbers = copy._numbers;
	}
	return *this;
}
Span::~Span() {}

void	Span::addNumber(int number) {
	if (_numbers.size() >= _nLimit)
		throw SpanFullException();
	_numbers.push_back(number); 
}

int		Span::shortestSpan() {
	if (_numbers.size() < 2)
		throw NoSpanException();
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int	minDiff = std::numeric_limits<int>::max();
	for (size_t i = 0; i < sorted.size() - 1; ++i) {
		int diff = sorted[i + 1] - sorted[i];
		if (diff < minDiff)
			minDiff = diff;
	}
	return minDiff;
}

int		Span::longestSpan() {
	if (_numbers.size() < 2)
		throw NoSpanException();

	int	min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return (max - min);
}