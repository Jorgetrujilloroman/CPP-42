#include <cstdlib>
#include <ctime>
#include <string>
#include "Array.hpp"

#define MAX_VAL 43

int main()
{
    // int array
    std::cout << "--- INT ARRAY ---" << std::endl;
    
    Array<int> numbers(MAX_VAL);
    std::cout << "Array size: " << numbers.size() << std::endl;

    for (size_t i = 0; i < numbers.size(); i++)
        numbers[i] = i * 10;

    std::cout << "First element: " << numbers[0] << std::endl;
    std::cout << "Last element: " << numbers[MAX_VAL - 1] << std::endl;
    
    
	Array<int> tmp = numbers;
	tmp[0] = 4242;
    std::cout << "Copy array tmp[0] modified to 4242." << std::endl;
    
    
    std::cout << "Original array numbers[0]: " << numbers[0] << std::endl;

    Array<int> assigned(1);
	std::cout << "Assigned size before: " << assigned.size() << std::endl;
    assigned = numbers;
    std::cout << "Assigned size after using operator =: " << assigned.size() << std::endl;
    assigned[0] = 999;
    std::cout << "Original numbers[0] after assigned mod: " << numbers[0] << std::endl;
	std::cout << "Assigned[0] value after assigned mod: " << assigned[0] << std::endl;

    // exception
    std::cout << "\n--- EXCEPTION ---" << std::endl;
    try
    {
        std::cout << "Trying numbers[MAX_VAL]: ";
        numbers[MAX_VAL] = 0;
    }
    catch(const Array<int>::IndexOutOfBounds& e)
    {
        std::cerr << "Caught: " << e.what() << std::endl;
    }
    
    try
    {
        std::cout << "Trying numbers[-1]: ";
        numbers[-1] = 0;
    }
    catch(const Array<int>::IndexOutOfBounds& e)
    {
        std::cerr << "Caught: " << e.what() << std::endl;
    }

    // String array
    std::cout << "\n--- STRING ARRAY ---" << std::endl;
    Array<std::string> str_arr(2);
    str_arr[0] = "k ase";
    str_arr[1] = "Mundo";
    
    Array<std::string> str_copy(str_arr);
    
    str_arr[0] = "ola";
    
    std::cout << "Original str_arr[0]: " << str_arr[0] << std::endl;
    std::cout << "Copy str_copy[0]:    " << str_copy[0] << std::endl;

    return 0;
}