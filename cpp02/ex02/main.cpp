/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrujil <jotrujil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:49:56 by jotrujil          #+#    #+#             */
/*   Updated: 2025/07/22 19:53:39 by jotrujil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;

std::cout << b << std::endl;

std::cout << Fixed::max( a, b ) << std::endl;

return 0;
}

// Full main test:

/*

void testComparisons(const Fixed& a, const Fixed& b) {
    std::cout << "Comparisons between a = " << a << " and b = " << b << std::endl;
    std::cout << "a > b  : " << (a > b) << std::endl;
    std::cout << "a < b  : " << (a < b) << std::endl;
    std::cout << "a >= b : " << (a >= b) << std::endl;
    std::cout << "a <= b : " << (a <= b) << std::endl;
    std::cout << "a == b : " << (a == b) << std::endl;
    std::cout << "a != b : " << (a != b) << std::endl;
    std::cout << std::endl;
}

void testArithmetic(const Fixed& a, const Fixed& b) {
    std::cout << "Arithmetic operations with a = " << a << " and b = " << b << std::endl;
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    if (b.toFloat() != 0.0f)
        std::cout << "a / b = " << (a / b) << std::endl;
    else
        std::cout << "a / b = division by zero error!" << std::endl;
    std::cout << std::endl;
}

void testIncrementDecrement(Fixed val) {
    std::cout << "Increment and Decrement tests starting from " << val << std::endl;
    std::cout << "Original: " << val << std::endl;

    std::cout << "Pre-increment: " << ++val << std::endl;
    std::cout << "After pre-increment: " << val << std::endl;

    std::cout << "Post-increment: " << val++ << std::endl;
    std::cout << "After post-increment: " << val << std::endl;

    std::cout << "Pre-decrement: " << --val << std::endl;
    std::cout << "After pre-decrement: " << val << std::endl;

    std::cout << "Post-decrement: " << val-- << std::endl;
    std::cout << "After post-decrement: " << val << std::endl;
    std::cout << std::endl;
}

void testMinMax(Fixed& a, Fixed& b) {
    std::cout << "Testing min and max:" << std::endl;
    std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;

    const Fixed ca = a;
    const Fixed cb = b;
    std::cout << "min(const a, const b) = " << Fixed::min(ca, cb) << std::endl;
    std::cout << "max(const a, const b) = " << Fixed::max(ca, cb) << std::endl;
    std::cout << std::endl;
}

int main() {
    std::cout << "==== Constructors and Output ====" << std::endl;
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    std::cout << "\n==== Increment and Decrement ====" << std::endl;
    std::cout << ++a << std::endl;  // pre-increment
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;  // post-increment
    std::cout << a << std::endl;

    std::cout << "\n==== More Arithmetic ====" << std::endl;
    Fixed x(10.5f);
    Fixed y(3);
    testArithmetic(x, y);
    testArithmetic(y, x);

    std::cout << "==== Complex Increment/Decrement Tests ====" << std::endl;
    testIncrementDecrement(Fixed(1.25f));

    std::cout << "==== Comparisons ====" << std::endl;
    testComparisons(x, y);
    testComparisons(x, x);

    std::cout << "==== Min and Max ====" << std::endl;
    testMinMax(x, y);

    std::cout << "==== Edge Cases ====" << std::endl;
    Fixed zero(0);
    Fixed neg(-4.75f);
    std::cout << "neg: " << neg << std::endl;
    testComparisons(neg, zero);
    testArithmetic(neg, zero);

    return 0;
}
*/