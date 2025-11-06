
#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <cstdlib>

using std::cout;
using std::endl;

RobotomyRequestForm::RobotomyRequestForm() : AForm("Generic Robotomy Request Form", 72, 45), _target("home") {
	cout << "A generic RobotomyRequestForm has been created!. Default target: " << this->_target << endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request Form", 72, 45), _target(target) {
	cout << "RobotomyRequestForm created. Target: " << this->_target << endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	cout << "This RobotomyRequestForm was recycled... (object destroyed)" << endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy), _target(copy._target) {
	cout << "Copy constructor called for RobotomyRequestForm: " << endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& copy) {
	if(this != &copy) {
		AForm::operator=(copy);
		cout << "RobotomyRequestForm copy assignment operator called\n";
	}
	return (*this);
}

void	RobotomyRequestForm::beExecuted() const {
	cout << "BRRRrrrRRRRmmmmmuuuRRRRmmmm... *Drilling noise* BRRRRRrrrrr BBRRRRRRR..." << endl;

	if (std::rand() % 2 == 0)
		cout << "Robotomy failed... " << this->_target << " couldn't be robotomized." << endl;
	else
		cout << this->_target << " has been successfully robotomized." << endl;
}

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& RobotomyRequestForm) {
	os << "RobotomyRequestForm: " << RobotomyRequestForm.getName() << ". Is signed?: " << RobotomyRequestForm.getIsSigned()
	<< ". Min sign grade: " << RobotomyRequestForm.getSignMinGrade() << ". Min Exec Grade: " << RobotomyRequestForm.getExecMinGrade() << endl;
	return os;
}