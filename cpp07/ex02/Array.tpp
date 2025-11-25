#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), _data(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _data(NULL) {
	_data = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& copy) : _size(copy._size), _data(NULL) {
	if(_size > 0) {
		_data = new T[_size];
		for(size_t i = 0; i < _size; i++)
			_data[i] = copy._data[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete [] _data;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy) {
	if (this != &copy) {
		delete [] _data;
		_size = copy._size;
		_data = NULL;

		if(_size > 0) {
		_data = new T[_size];
		for(size_t i = 0; i < _size; i++)
			_data[i] = copy._data[i];
		}
	}
	return *this;
}

template <typename T>
T&	Array<T>::operator[](size_t index) {
	if (index >= _size)
		throw IndexOutOfBounds();
	return _data[index];
}

template <typename T>
const T&	Array<T>::operator[](size_t index) const {
	if (index >= _size)
		throw IndexOutOfBounds();
	return _data[index];
}

template <typename T>
size_t	Array<T>::size() const {
	return _size;
}
