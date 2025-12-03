#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int	main() {

	std::cout << "\n\n--- Vector ---" << std::endl;
	std::vector<int> vector_numbers;

	vector_numbers.push_back(13);
	vector_numbers.push_back(12);
	vector_numbers.push_back(1312);

	int	exist = 1312;
	int not_exist = 7;

	std::cout << "Searching for target number: " << exist << std::endl;
	try {
		std::vector<int>::iterator it = easyfind(vector_numbers, exist);
		std::cout << "Number: " << *it << " was found" << std::endl;
	} catch (const NotFoundException& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nSearching for target number: " << not_exist << std::endl;
	try {
		std::vector<int>::iterator it = easyfind(vector_numbers, not_exist);
		std::cout << "Number: " << *it << " was found" << std::endl;
	} catch (const NotFoundException& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n\n--- List ---" << std::endl;
	std::list<int> list_numbers;

	list_numbers.push_back(17);
	list_numbers.push_back(42);
	list_numbers.push_back(69);
	list_numbers.push_back(420);
	list_numbers.push_back(666);

	int	exist_too = 42;
	int not_exist_either = 999;

	std::cout << "Searching for target number: " << exist << std::endl;
	try {
		std::list<int>::iterator it = easyfind(list_numbers, exist_too);
		std::cout << "Number: " << *it << " was found" << std::endl;
	} catch (const NotFoundException& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nSearching for target number: " << not_exist << std::endl;
	try {
		std::list<int>::iterator it = easyfind(list_numbers, not_exist_either);
		std::cout << "Number: " << *it << " was found" << std::endl;
	} catch (const NotFoundException& e){
		std::cout << "Exception: " << e.what() << std::endl;
	}
}