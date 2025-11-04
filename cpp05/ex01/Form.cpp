
#include "Form.hpp"

using std::cout;
using std::endl;

const char*	Form::GradeTooHighException::what() const throw() {
	return "Grade is too high (must be >= 1)";
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "Grade is too low (must be <= 150)";
}

Form::Form() : _name("Funny Form"), _isSigned(false),  _signMinGrade(75), _execMinGrade(75) {
	cout << "A generic Form has been created!. Default sign and exec grade is 75" << endl;
}

Form::Form(const std::string& name, int signMinGrade, int execMinGrade) : _name(name), _isSigned(false),
_signMinGrade(signMinGrade), _execMinGrade(execMinGrade) {
	if (signMinGrade < 1 || execMinGrade < 1) 
		throw Form::GradeTooHighException();
	if (signMinGrade > 150 || execMinGrade > 150) 
		throw Form::GradeTooLowException();

	cout << "---" << endl;
	cout << "Form named: " << _name << " has been created" << endl;
	cout << "- Minimum grade to sign: " << _signMinGrade << endl;
	cout << "- Minimum grade to exec: " << _execMinGrade << endl;
	cout << "---" << endl;
}

Form::~Form() {
	cout << "This Form was recycled... (object destroyed)" << endl;
}

Form::Form(const Form& copy) : _name(copy._name), _signMinGrade(copy._signMinGrade), _execMinGrade(copy._execMinGrade) {
	cout << "Copy constructor called for Form: " << _name << endl;
}

Form& Form::operator= (const Form& copy) {
	if(this != &copy) {
		cout << "Form copy assignment operator called\n";
		this->_isSigned = copy._isSigned;
	}
	return (*this);
}

const std::string&	Form::getName() const {
	return this->_name;
}

bool	Form::getIsSigned() const {
	return this->_isSigned;
}

int	Form::getSignMinGrade() const {
	return this->_signMinGrade;
}

int	Form::getExecMinGrade() const {
	return this->_execMinGrade;
}

void	Form::beSigned(const Bureaucrat& signer){
	if (this->_isSigned == true) 
		return ;
	if (signer.getGrade() <= this->_signMinGrade) 
		this->_isSigned = true;
	else 
		throw Form::GradeTooLowException();
}

std::ostream&	operator<<(std::ostream& os, const Form& Form) {
	os << "Form: " << Form.getName() << ". Is signed?: " << Form.getIsSigned()
	<< ". Min sign grade: " << Form.getSignMinGrade() << ". Min Exec Grade: " << Form.getExecMinGrade() << endl;
	return os;
}