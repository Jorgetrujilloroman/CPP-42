
#include "Bureaucrat.hpp"
#include "Form.hpp"

using std::cout;
using std::endl;

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high (must be >= 1)";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low (must be <= 150)";
}

Bureaucrat::Bureaucrat() : _name("Generic Bureaucrat"), _grade(150) {
	cout << "A Bureaucrat has appeared!" << endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade) {
	if (grade < 1) 
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150) 
		throw Bureaucrat::GradeTooLowException();
	cout << "Bureaucrat " << _name << " with grade: " << _grade << " created" << endl;
}

Bureaucrat::~Bureaucrat() {
	cout << "This Bureaucrat was fired... (object destroyed)" << endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {
	cout << "Copy constructor called for Bureaucrat: " << _name << endl;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& copy) {
	if(this != &copy) {
		cout << "Bureaucrat copy assignment operator called\n";
		this->_grade = copy._grade;
	}
	return (*this);
}

const std::string&	Bureaucrat::getName() const {
	return this->_name;
}

int					Bureaucrat::getGrade() const {
	return this->_grade;
}

void				Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	cout << this->_name << "'s grade incremented to: " << this->_grade << endl;
}

void				Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	cout << this->_name << "'s grade decremented to: " << this->_grade << endl;
}

void				Bureaucrat::signForm(Form& form) {
	bool	wasSigned = form.getIsSigned();

	try
	{
		form.beSigned(*this);

		if (wasSigned && form.getIsSigned())
			cout << this->_name << " couldn't sign the form named: "
		 		<< form.getName() << " because it was already signed." << endl;
		else
			cout << this->_name << " has successfully signed a form named: "
		 		<< form.getName() << endl;
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cerr << this->_name << " couldn't sign form named: " << form.getName() 
		 << " because " << e.what() << endl;
	}
	catch(std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign form named: " << form.getName() 
		 << " because of an unexpected error" << e.what() << endl;
	}
	
}
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}