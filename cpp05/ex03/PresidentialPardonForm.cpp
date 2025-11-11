
#include "PresidentialPardonForm.hpp"
#include <fstream>

using std::cout;
using std::endl;

PresidentialPardonForm::PresidentialPardonForm() : AForm("Generic Presidential Pardon Form", 25, 5), _target("home") {
	cout << "A generic PresidentialPardonForm has been created!. Default target: " << this->_target << endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {
	cout << "PresidentialPardonForm created. Target: " << this->_target << endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	cout << "This PresidentialPardonForm was recycled... (object destroyed)" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy), _target(copy._target) {
	cout << "Copy constructor called for PresidentialPardonForm: " << endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& copy) {
	if(this != &copy) {
		AForm::operator=(copy);
		cout << "PresidentialPardonForm copy assignment operator called\n";
	}
	return (*this);
}

void	PresidentialPardonForm::beExecuted() const {
	cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << endl;
}

std::ostream&	operator<<(std::ostream& os, const PresidentialPardonForm& PresidentialPardonForm) {
	os << "PresidentialPardonForm: " << PresidentialPardonForm.getName() << ". Is signed?: " << PresidentialPardonForm.getIsSigned()
	<< ". Min sign grade: " << PresidentialPardonForm.getSignMinGrade() << ". Min Exec Grade: " << PresidentialPardonForm.getExecMinGrade() << endl;
	return os;
}