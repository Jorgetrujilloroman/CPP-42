#include <ScalarConverter.hpp>
#include <cstdlib>
#include <stdio>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& copy) {}
ScalarConverter& ScalarConverter::operator= (const ScalarConverter& copy) {}
ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(const std::string& literal) {

	double	value;
	char*	endptr;
	bool	pseudo_literal = false;

	if (literal.length() == 3 && (literal[0] == '\'') && (literal[2] == '\'')) {
		value = static_cast<double>(literal[1]);
	}
	else if (literal == "nan" || literal == "+inf" || literal == "-inf" ||
		 literal == "nanf" || literal == "+inff" || literal == "-inff") {
			pseudo_literal = true;
	}
	else {
		value = std::strtod(literal.c_str(), &endptr);
		if (*endptr != '\0' && !(*endptr == 'f' && *(endptr + 1) == '\0')) {
			std::cerr << "Error: Invalid numeric literal format" << std::endl;
		}
		else {
			
		}
	}

}