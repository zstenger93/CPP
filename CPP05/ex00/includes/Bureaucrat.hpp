#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <ostream>

#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define END "\033[1;39m"

#define CONSTRUCTOR "Bureaucraft default constructor called."
#define GTL "Provided grade is too low."
#define GTH "Provided grade is too high."

class Bureaucrat {
   public:
	Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &cpy);
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const &rhs);
	static const int MinGrade = 1;
	static const int MaxGrade = 150;
	std::string const &getName() const;
	void getGrade() const;	// lowest 1 highest is 150
	void IncrementGrade();
	void DecrementGrade();

   private:
	int grade;
	std::string const name;

	class GradeTooLowExecption : public std::exception {
	   public:
		virtual const char *what() const throw();
	};

	class GradeTooHighExecption : public std::exception {
	   public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif