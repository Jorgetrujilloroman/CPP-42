#pragma once

#include <string>
#include <iostream>

class Form;

class Bureaucrat {
private:
	const std::string	_name;
	int					_grade;
public:
	class	GradeTooHighException : public std::exception {
		public:
			const char*	what() const throw();
	};
	class	GradeTooLowException : public std::exception {
		public:
			const char*	what() const throw();
	};
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator= (const Bureaucrat& copy);
	~Bureaucrat();
	
	const std::string&	getName() const;
	int					getGrade() const;

	void				incrementGrade();
	void				decrementGrade();
	void				signForm(Form& form);
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);