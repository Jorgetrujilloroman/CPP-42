#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

using std::cout;
using std::endl;

const char*	Intern::FormNotExsist::what() const throw() {
	return "This form does not exist";
}

Intern::Intern() {
	cout << "A Intern has started his non-paid learning journey with us!" << endl;
}

Intern::~Intern() {
	cout << "This Intern was kindly fired without earning a single euro... (object destroyed)" << endl;
}

Intern::Intern(const Intern& copy) {
	(void)copy;
	cout << "Copy constructor called for Intern" << endl;
}

Intern& Intern::operator= (const Intern& copy) {
	(void)copy;
	cout << "Intern copy assignment operator called." << endl;
	return (*this);
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& formTarget) const {
	AForm* newForm = NULL;

	std::string	formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	int i;
	for (i = 0; i < 3; i++) {
		if (formName == formNames[i])
			break;
	}

	switch (i) {
		case 0:
			newForm = new ShrubberyCreationForm(formTarget);
			break ;
		case 1:
			newForm = new RobotomyRequestForm(formTarget);
			break ;
		case 2:
			newForm = new PresidentialPardonForm(formTarget);
			break ;
		default:
			throw Intern::FormNotExsist();
	}

	cout << "Intern creates " << newForm->getName() << endl;
	return newForm;
}
