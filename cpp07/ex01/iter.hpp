#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void	iter(T *array, const size_t len, F func) {
	if (!array)
		return ;
	for (size_t i = 0; i < len; i++) {
		func(array[i]);
	}	
}

#endif