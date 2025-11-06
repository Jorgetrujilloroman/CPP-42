
#include "AForm.hpp"
#include "Bureaucrat.hpp"

using std::cout;
using std::endl;

const char*	AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char*	AForm::FormNotSignedException::what() const throw() {
	return "Can't execute form: not signed";
}

AForm::AForm() : _name("Funny AForm"), _isSigned(false),  _signMinGrade(75), _execMinGrade(75) {
	cout << "A generic AForm has been created!. Default sign and exec grade is 75" << endl;
}

AForm::AForm(const std::string& name, int signMinGrade, int execMinGrade) : _name(name), _isSigned(false),
_signMinGrade(signMinGrade), _execMinGrade(execMinGrade) {
	if (signMinGrade < 1 || execMinGrade < 1) 
		throw AForm::GradeTooHighException();
	if (signMinGrade > 150 || execMinGrade > 150) 
		throw AForm::GradeTooLowException();

	cout << "---" << endl;
	cout << "AForm named: " << _name << " has been created" << endl;
	cout << "- Minimum grade to sign: " << _signMinGrade << endl;
	cout << "- Minimum grade to exec: " << _execMinGrade << endl;
	cout << "---" << endl;
}

AForm::~AForm() {
	cout << "This AForm was recycled... (object destroyed)" << endl;
}

AForm::AForm(const AForm& copy) : _name(copy._name), _isSigned(copy._isSigned), _signMinGrade(copy._signMinGrade),
 _execMinGrade(copy._execMinGrade) {
	cout << "Copy constructor called for AForm: " << _name << endl;
}

AForm& AForm::operator= (const AForm& copy) {
	if(this != &copy) {
		cout << "AForm copy assignment operator called\n";
		this->_isSigned = copy._isSigned;
	}
	return (*this);
}

const std::string&	AForm::getName() const {
	return this->_name;
}

bool	AForm::getIsSigned() const {
	return this->_isSigned;
}

int	AForm::getSignMinGrade() const {
	return this->_signMinGrade;
}

int	AForm::getExecMinGrade() const {
	return this->_execMinGrade;
}

void	AForm::beSigned(const Bureaucrat& signer){
	if (this->_isSigned == true) 
		return ;
	if (signer.getGrade() <= this->_signMinGrade) 
		this->_isSigned = true;
	else 
		throw AForm::GradeTooLowException();
}

void	AForm::execute(Bureaucrat const & executor) const {
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_execMinGrade)
		throw AForm::GradeTooLowException();
	this->beExecuted();
}

std::ostream&	operator<<(std::ostream& os, const AForm& AForm) {
	os << "AForm: " << AForm.getName() << ". Is signed?: " << AForm.getIsSigned()
	<< ". Min sign grade: " << AForm.getSignMinGrade() << ". Min Exec Grade: " << AForm.getExecMinGrade() << endl;
	return os;
}