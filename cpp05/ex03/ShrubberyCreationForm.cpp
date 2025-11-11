
#include "ShrubberyCreationForm.hpp"
#include <fstream>

using std::cout;
using std::endl;

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Generic Shrubbery Form", 145, 137), _target("home") {
	cout << "A generic ShrubberyCreationForm has been created!. Default target: " << this->_target << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation Form", 145, 137), _target(target) {
	cout << "ShrubberyCreationForm created. Target: " << this->_target << endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	cout << "This ShrubberyCreationForm was recycled... (object destroyed)" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target) {
	cout << "Copy constructor called for ShrubberyCreationForm: " << endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& copy) {
	if(this != &copy) {
		AForm::operator=(copy);
		cout << "ShrubberyCreationForm copy assignment operator called\n";
	}
	return (*this);
}

void	ShrubberyCreationForm::beExecuted() const {
	std::string	filename = this->_target + "_shrubbery";
	std::ofstream outfile(filename.c_str());

	if (!outfile) {
		std::cerr << "Error: Could not open file" << filename << endl;
		return ;
	}

	outfile << "       _-_" << endl;
    outfile << "   /~~   ~~\\" << endl;
    outfile << " /~~         ~~\\" << endl;
    outfile << "{               }" << endl;
    outfile << " \\  _-     -_  /" << endl;
    outfile << "   ~  \\\\ //  ~" << endl;
    outfile << "_- -   | | _- _" << endl;
    outfile << "  _ -  | |   -_" << endl;
    outfile << "      // \\\\" << endl;

	outfile.close();
	cout << this->getName() << ": File '" << filename << "' successfully created." << endl;
}

std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& ShrubberyCreationForm) {
	os << "ShrubberyCreationForm: " << ShrubberyCreationForm.getName() << ". Is signed?: " << ShrubberyCreationForm.getIsSigned()
	<< ". Min sign grade: " << ShrubberyCreationForm.getSignMinGrade() << ". Min Exec Grade: " << ShrubberyCreationForm.getExecMinGrade() << endl;
	return os;
}