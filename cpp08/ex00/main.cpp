#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

using std::cout;
using std::endl;

int	main() {

	cout << "\n\n--- Vector ---" << endl;
	std::vector<int> vector_numbers;

	vector_numbers.push_back(13);
	vector_numbers.push_back(12);
	vector_numbers.push_back(1312);

	int	exist = 1312;
	int not_exist = 7;

	cout << "Searching for target number: " << exist << endl;
	try {
		std::vector<int>::iterator it = easyfind(vector_numbers, exist);
		cout << "Number: " << *it << " was found" << endl;
	} catch (const NotFoundException& e){
		cout << "Exception: " << e.what() << endl;
	}

	cout << "\nSearching for target number: " << not_exist << endl;
	try {
		std::vector<int>::iterator it = easyfind(vector_numbers, not_exist);
		cout << "Number: " << *it << " was found" << endl;
	} catch (const NotFoundException& e){
		cout << "Exception: " << e.what() << endl;
	}

	cout << "\n\n--- List ---" << endl;
	std::list<int> list_numbers;

	list_numbers.push_back(17);
	list_numbers.push_back(42);
	list_numbers.push_back(69);
	list_numbers.push_back(420);
	list_numbers.push_back(666);

	int	exist_too = 42;
	int not_exist_either = 999;

	cout << "Searching for target number: " << exist << endl;
	try {
		std::list<int>::iterator it = easyfind(list_numbers, exist_too);
		cout << "Number: " << *it << " was found" << endl;
	} catch (const NotFoundException& e){
		cout << "Exception: " << e.what() << endl;
	}

	cout << "\nSearching for target number: " << not_exist << endl;
	try {
		std::list<int>::iterator it = easyfind(list_numbers, not_exist_either);
		cout << "Number: " << *it << " was found" << endl;
	} catch (const NotFoundException& e){
		cout << "Exception: " << e.what() << endl;
	}
}