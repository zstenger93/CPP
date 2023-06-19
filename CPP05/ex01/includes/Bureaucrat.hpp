#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <ostream>

#include "BureaucraftDefines.hpp"

class Form;

class Bureaucrat {
   public:
	Bureaucrat();
	Bureaucrat(std::string const &_name, int _grade);
	Bureaucrat(Bureaucrat const &cpy);
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const &rhs);
	static const int MinGrade = 150;
	static const int MaxGrade = 1;
	std::string const &getName() const;
	int getGrade() const;  // lowest 1 highest is 150
	void IncrementGrade();
	void DecrementGrade();
	void signForm(Form &formName);

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
	int grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif