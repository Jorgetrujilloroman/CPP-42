#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstddef>

template <typename T>
class Array {
private:
	size_t	_size;
	T* 		_data;
public:

	class IndexOutOfBounds : public std::exception {
		public:
			const char* what() const throw() {
				return "Index out of bounds";
			}
	};

	Array();
	Array(unsigned int n);
	Array(const Array& copy);
	Array& operator=(const Array& copy);
	~Array();

	T&	operator[](size_t index);
	const T&	operator[](size_t index) const;

	size_t	size() const;
};

#include "Array.tpp"

#endif