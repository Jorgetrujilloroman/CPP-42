#pragma once

#include <string>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator= (const ScalarConverter& copy);
		~ScalarConverter();
	public:
		static void	convert(const std::string& literal);
};
