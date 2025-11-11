#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
	const std::string	_target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm& operator= (const ShrubberyCreationForm& copy);
	~ShrubberyCreationForm();

	void		beExecuted() const;
};

std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& ShrubberyCreationForm);