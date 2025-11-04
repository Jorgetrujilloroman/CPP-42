#pragma once

#include <string>
#include <iostream>

class Bureaucrat;

class Form {
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signMinGrade;
	const int			_execMinGrade;
public:
	class	GradeTooHighException : public std::exception {
		public:
			const char*	what() const throw();
	};
	class	GradeTooLowException : public std::exception {
		public:
			const char*	what() const throw();
	};

	Form();
	Form(const std::string& name, int signMinGrade, int execMinGrade);
	Form(const Form& copy);
	Form& operator= (const Form& copy);
	~Form();

	const std::string&	getName() const;
	bool 				getIsSigned() const;
	int					getSignMinGrade() const;
	int					getExecMinGrade() const;

	void				beSigned(const Bureaucrat& signer);
};

std::ostream&	operator<<(std::ostream& os, const Form& form);