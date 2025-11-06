#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	const std::string	_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	RobotomyRequestForm& operator= (const RobotomyRequestForm& copy);
	~RobotomyRequestForm();

	void		beExecuted() const;
};

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& RobotomyRequestForm);