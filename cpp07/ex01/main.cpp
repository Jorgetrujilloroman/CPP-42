#include <iostream>
#include "iter.hpp"

using std::cout;
using std::endl;

// Print element (const)
template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

// Increment element (non const)
template <typename T>
void incrementElement(T& element) {
    ++element;
}

int main() {

    // Int Array
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    cout << "\nInteger array before incrementing: ";
    iter(intArray, intArraySize, &printElement<int>);
    cout << endl;

    iter(intArray, intArraySize, &incrementElement<int>);

    cout << "Int array after incrementing: ";
    iter(intArray, intArraySize, &printElement<int>);
    cout << endl << endl;

    // String array
    std::string strArray[] = {"Hola", "k", "ase"};
    size_t strArraySize = sizeof(strArray) / sizeof(strArray[0]);

    cout << "String array: ";
    iter(strArray, strArraySize, &printElement<std::string>);
    cout << endl << endl;

    // Char array
    char charArray[] = {'J', 'o', 'a', 'q', 'u', 'i', 'n'};
    size_t charArraySize = sizeof(charArray) / sizeof(charArray[0]);

    cout << "Char array: ";
    iter(charArray, charArraySize, &printElement<char>);
    cout << endl << "Encrypted char array: ";
    iter(charArray, charArraySize, &incrementElement<char>);
    iter(charArray, charArraySize, &printElement<char>);
    cout << endl << endl;

    return 0;
}