
#include "Bureaucrat.hpp"

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high (must be >= 1)";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low (must be <= 150)";
}

Bureaucrat::Bureaucrat() : _name("Generic Bureaucrat"), _grade(150) {
	std::cout << "A Bureaucrat has appeared!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade) {
	if (grade < 1) 
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150) 
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat " << _name << " with grade: " << _grade << " created" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "This Bureaucrat was fired... (object destroyed)" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {
	std::cout << "Copy constructor called for Bureaucrat: " << _name << std::endl;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& copy) {
	if(this != &copy) {
		std::cout << "Bureaucrat copy assignment operator called\n";
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

void				Bureaucrat::incrementGrade(){
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
	std::cout << this->_name << "'s grade incremented to: " << this->_grade << std::endl;
}

void				Bureaucrat::decrementGrade(){
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
	std::cout << this->_name << "'s grade decremented to: " << this->_grade << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade" << bureaucrat.getGrade() << ".";
	return os;
}