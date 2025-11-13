#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <cctype>
#include <cmath>
#include <iomanip>

using std::cout;
using std::endl;

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	(void)copy;
}

ScalarConverter& ScalarConverter::operator= (const ScalarConverter& copy) {
	(void)copy;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(const std::string& literal) {
	
	cout << std::setprecision(10);

	double	value;
	char*	endptr = NULL;
	bool	is_char_literal = false;
	bool	is_pseudo_literal = false;

	// Identify the type
	if ((literal.length() == 3 && (literal[0] == '\'') && (literal[2] == '\'')) ||
		(literal.length() == 1 && !std::isdigit(literal[0]) && literal[0] != '.' &&
		literal[0] != '+' && literal[0] != '-') ) {
		if (literal.length() == 3)
			value = static_cast<double>(literal[1]);
		else if (literal.length() == 1)
			value = static_cast<double>(literal[0]);
		is_char_literal = true;
	}
	else if (literal == "nan" || literal == "+inf" || literal == "-inf" ||
		 literal == "nanf" || literal == "+inff" || literal == "-inff") {
			is_pseudo_literal = true;
			value = std::strtod(literal.c_str(), NULL);
	}
	else {
		value = std::strtod(literal.c_str(), &endptr);
		if (*endptr != '\0' && !(*endptr == 'f' && *(endptr + 1) == '\0')) {
			std::cerr << "Error: Invalid numeric literal format" << std::endl;
			return;
		}
	}

	// Convert and print
	cout << "char: ";
	if (is_pseudo_literal || value < static_cast<double>(std::numeric_limits<char>::min()) || 
		value > static_cast<double>(std::numeric_limits<char>::max()))
		cout << "impossible" << endl;
	else {
		char c = static_cast<char>(value);
		if (std::isprint(c))
			cout << "'" << c << "'" << endl;
		else
			cout << "Non-displayable" << endl;
	}

	cout << "int: ";
	if (is_pseudo_literal || value < static_cast<double>(std::numeric_limits<int>::min()) || 
		value > static_cast<double>(std::numeric_limits<int>::max()) || std::isnan(value) ||
		 std::isinf(value))
		cout << "impossible" << endl;
	else
		cout << static_cast<int>(value) << endl;

	cout << "float: ";
	if (is_pseudo_literal) {
		if (std::isnan(value))
			cout << "nanf" << endl;
		else if (std::isinf(value)) {
			if (value > 0)
				cout << "+inff" << endl;
			else
				cout << "-inff" << endl;
		}
	}
	else {
		float f = static_cast<float>(value);

		if (f == static_cast<int>(f) && !is_char_literal)
			cout << f << ".0f" << endl;
		else 
			cout << f << "f" << endl;
	}

	cout << "double: ";
	if (is_pseudo_literal) {
		if (std::isnan(value))
			cout << "nan" << endl;
		else if (std::isinf(value)) {
			if (value > 0)
				cout << "+inf" << endl;
			else
				cout << "-inf" << endl;
		}
	}
	else {
		if (value == static_cast<int>(value) && !is_char_literal)
			cout << value << ".0" << endl;
		else 
			cout << value << endl;
	}
}