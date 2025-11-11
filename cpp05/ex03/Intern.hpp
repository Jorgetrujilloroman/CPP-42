#pragma once

#include <string>
#include <iostream>

class AForm;

class Intern {
public:

	class	FormNotExsist : public std::exception {
		public:
			const char*	what() const throw();
	};

	Intern();
	Intern(const Intern& copy);
	Intern& operator= (const Intern& copy);
	~Intern();

	AForm*	makeForm(const std::string& formName, const std::string& formTarget) const;
};