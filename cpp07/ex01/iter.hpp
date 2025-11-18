#include <cstddef>

template <typename T, typename U>
void	iter(T* array, const size_t &len, U func) {
	if (!array)
		return ;
	for (size_t i = 0; i < len; i++) {
		func(array[i]);
	}	
}