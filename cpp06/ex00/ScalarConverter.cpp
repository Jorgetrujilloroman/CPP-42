#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <cctype>

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

	double	value;
	char*	endptr;
	bool	is_pseudo_literal = false;


	// Identify the type
	if (literal.length() == 3 && (literal[0] == '\'') && (literal[2] == '\'')) {
		value = static_cast<double>(literal[1]);
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

	
}