#include "Span.hpp"
#include <ctime>

int main()
{
    std::cout << "* Subject Test *" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\n* Exceptions *" << std::endl;
    try {
        Span full(1);
        full.addNumber(42);
        full.addNumber(24);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Span empty(5);
        empty.shortestSpan();
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n* Range Test (addNumbers) *" << std::endl;
    Span rangeSpan(10);
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    rangeSpan.addNumbers(v.begin(), v.end());
    std::cout << "Shortest: " << rangeSpan.shortestSpan() << std::endl;
    std::cout << "Longest: " << rangeSpan.longestSpan() << std::endl;

    std::cout << "\n* Big Test (10,000+ numbers) *" << std::endl;
    Span bigSpan(15000);
    std::vector<int> bigV;
    std::srand(std::time(0));
    for (int i = 0; i < 15000; i++)
        bigV.push_back(std::rand());
    
    bigSpan.addNumbers(bigV.begin(), bigV.end());
    std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest: " << bigSpan.longestSpan() << std::endl;

    return 0;
}