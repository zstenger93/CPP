#ifndef FORM_HPP
#define FORM_HPP

#include <exception>

#include "Bureaucrat.hpp"
#include "FormDefines.hpp"

class Bureaucrat;

class Form {
   public:
	Form();
	Form(std::string const &_formName, bool _isSigned, const int _gradeRequirement);
	Form(Form const &cpy);
	~Form();
	Form &operator=(Form const &rhs);
	static const int MinGrade = 150;
	static const int MaxGrade = 1;
	std::string const &Name() const;
	void beSigned(Bureaucrat &bureaucrap);
	int requirementGrade();
	bool isAlreadySigned();

	class FormGradeTooLowExecption : public std::exception {
	   public:
		virtual const char *what() const throw();
	};

	class FormGradeTooHighExecption : public std::exception {
	   public:
		virtual const char *what() const throw();
	};

	class FormCannotBeSignedExecption : public std::exception {
	   public:
		virtual const char *what() const throw();
	};

	class FormIsAlreadySignedExecption : public std::exception {
	   public:
		virtual const char *what() const throw();
	};

   private:
	std::string const formName;
	bool isSigned;				 // is the form signed
	const int gradeRequirement;	 // to execute
};

std::ostream &operator<<(std::ostream &os, Form &form);

#endif