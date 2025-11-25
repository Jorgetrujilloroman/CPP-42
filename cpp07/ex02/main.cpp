#include <cstdlib>
#include <ctime>
#include <string>
#include "Array.hpp"

using std::cout;
using std::endl;

#define MAX_VAL 43

int main()
{
    // int array
    cout << "--- INT ARRAY ---" << endl;
    
    Array<int> numbers(MAX_VAL);
    cout << "Array size: " << numbers.size() << endl;

    for (size_t i = 0; i < numbers.size(); i++)
        numbers[i] = i * 10;

    cout << "First element: " << numbers[0] << endl;
    cout << "Last element: " << numbers[MAX_VAL - 1] << endl;
    
    
	Array<int> tmp = numbers;
	tmp[0] = 4242;
    cout << "Copy array tmp[0] modified to 4242." << endl;
    
    
    cout << "Original array numbers[0]: " << numbers[0] << endl;

    Array<int> assigned(1);
	cout << "Assigned size before: " << assigned.size() << endl;
    assigned = numbers;
    cout << "Assigned size after using operator =: " << assigned.size() << endl;
    assigned[0] = 999;
    cout << "Original numbers[0] after assigned mod: " << numbers[0] << endl;
	cout << "Assigned[0] value after assigned mod: " << assigned[0] << endl;

    // exception
    cout << "\n--- EXCEPTION ---" << endl;
    try
    {
        cout << "Trying numbers[MAX_VAL]: ";
        numbers[MAX_VAL] = 0;
    }
    catch(const Array<int>::IndexOutOfBounds& e)
    {
        std::cerr << "Caught: " << e.what() << endl;
    }
    
    try
    {
        cout << "Trying numbers[-1]: ";
        numbers[-1] = 0;
    }
    catch(const Array<int>::IndexOutOfBounds& e)
    {
        std::cerr << "Caught: " << e.what() << endl;
    }

    // String array
    cout << "\n--- STRING ARRAY ---" << endl;
    Array<std::string> str_arr(2);
    str_arr[0] = "k ase";
    str_arr[1] = "Mundo";
    
    Array<std::string> str_copy(str_arr);
    
    str_arr[0] = "ola";
    
    cout << "Original str_arr[0]: " << str_arr[0] << endl;
    cout << "Copy str_copy[0]:    " << str_copy[0] << endl;

    return 0;
}