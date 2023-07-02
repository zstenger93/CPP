#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <ostream>

#include "BureaucraftDefines.hpp"

class AForm;

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
	void signForm(AForm &formName);
	void executeForm(AForm const &form);

	class GradeTooLowException : public std::exception {
	   public:
		const char *what() const throw();
	};

	class GradeTooHighException : public std::exception {
	   public:
		const char *what() const throw();
	};

	class WrongIncrementException : public std::exception {
	   public:
		const char *what() const throw();
	};

	class WrongDecrementException : public std::exception {
	   public:
		const char *what() const throw();
	};

   private:
	std::string const name;
	int grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif