#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <ostream>

#define RED "\033[1;31m"
#define END "\033[1;39m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"

#define DEFBURO "Default Bureaucrat"
#define ASSIGNMENT " assignment operator  called."
#define BUREAUCRAT "\033[1;33mBureaucrat \033[1;39m"
#define DESTRUCTOR " \033[1;31mdestructor called.\033[1;39m"
#define CONSTRUCTOR "\033[1;33m constructor called.\n\033[1;39m"
#define COPYCON " \033[1;33mcopy constructor called.\033[1;39m"
#define INCR " \033[1;34mgrade has been incremented.\033[1;39m"
#define DECR " \033[1;34mgrade has been decremented.\033[1;39m"
#define WI "\033[1;31m's grade would be too high, cannot increment.\n\033[1;39m"
#define WD "\033[1;31m's grade would be too low, cannot decrement.\n\033[1;39m"
#define GTL "\033[1;31m's grade is too low, cannot initialize.\n\033[1;39m"
#define GTH "\033[1;31m's grade is too high, cannot initialize.\n\033[1;39m"

#define BAD_INPUT "Wrong testcase ID. Available options are:"
#define TEST0 "      nothing -> options"
#define TEST1 "         1    -> test for increment"
#define TEST2 "         2    -> test for decrement"
#define TEST3 "         3    -> test for wrong grade range while increment"
#define TEST4 "         4    -> test for wrong grade range while decrement"
#define TEST5 "         5    -> test for initializing with too low grade"
#define TEST6 "         6    -> test for initializing with too  grade"

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