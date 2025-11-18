#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(const T& element) {
    std::cout << element << " ";
}

template <typename T>
void increment(T& element) {
    element++;
}

void increment(std::string& s) {
    s += "!";
}

int main() {
    int nums[] = {1, 2, 3};
    size_t len_n = 3;

    std::cout << "Original nums: ";
    iter(nums, len_n, print<int>); // CORREGIDO
    std::cout << std::endl;

    iter(nums, len_n, increment<int>); // CORREGIDO

    std::cout << "Modified nums: ";
    iter(nums, len_n, print<int>); // CORREGIDO
    std::cout << std::endl;

    std::cout << "---" << std::endl;

    std::string words[] = {"Hola", "42", "Cplusplus"};
    size_t len_w = 3;

    std::cout << "Original words: ";
    iter(words, len_w, print<std::string>); // CORREGIDO
    std::cout << std::endl;

	iter(words, len_w, increment);

    std::cout << "Modified words: ";
    iter(words, len_w, print<std::string>); // CORREGIDO
    std::cout << std::endl;

    return 0;
}