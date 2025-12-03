#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception {
	public:
		const char *what() const throw() {
			return "Number not found in container";
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int n) {
	
	typename T::iterator result = std::find(container.begin(), container.end(), n);
	
	if (result == container.end())
		throw NotFoundException();
	else
		return result;
}

#endif