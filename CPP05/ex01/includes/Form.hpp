#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
   public:
	Form();
	Form(std::string const &_name, int _grade);
	Form(Form const &cpy);
	~Form();
	Form &operator=(Form const &rhs);
	static const int MinGrade = 150;
	static const int MaxGrade = 1;
	std::string const &getName() const;
	int getGrade() const;  // lowest 1 highest is 150
	void beSigned(Bureaucrat &bureaucrap);
	bool getIsSigned();
	int getGradeRequirement();	

	class GradeTooLowExecption : public std::exception {
	   public:
		virtual const char *what() const throw();
	};

	class GradeTooHighExecption : public std::exception {
	   public:
		virtual const char *what() const throw();
	};

	class WrongIncrement : public std::exception {
	   public:
		virtual const char *what() const throw();
	};

	class WrongDecrement : public std::exception {
	   public:
		virtual const char *what() const throw();
	};

   private:
	std::string const name;
	const int grade;
	bool isSigned; // is the form signed
	const int gradeRequirement; // to execute
};

std::ostream &operator<<(std::ostream &os, Form const &Form);

#endif