#pragma once

#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
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

	class	FormNotSignedException : public std::exception {
		public:
			const char*	what() const throw();
	};

	AForm();
	AForm(const std::string& name, int signMinGrade, int execMinGrade);
	AForm(const AForm& copy);
	AForm& operator= (const AForm& copy);
	~AForm();

	const std::string&	getName() const;
	bool 				getIsSigned() const;
	int					getSignMinGrade() const;
	int					getExecMinGrade() const;

	void				beSigned(const Bureaucrat& signer);
	void				execute(Bureaucrat const & executor) const;
	virtual void		beExecuted() const = 0;
};

std::ostream&	operator<<(std::ostream& os, const AForm& AForm);