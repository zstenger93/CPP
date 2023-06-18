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
#define BUREAUCRAT "\033[1;33mBureaucrat\033[1;39m"
#define DESTRUCTOR " \033[1;31mdestructor called.\033[1;39m"
#define GTL "\033[1;31mProvided grade is too low.\n\033[1;39m"
#define GTH "\033[1;31mProvided grade is too high.\n\033[1;39m"
#define COPYCON " \033[1;33mcopy constructor called.\033[1;39m"
#define INCR " \033[1;34mgrade has been incremented.\033[1;39m"
#define DECR " \033[1;34mgrade has been decremented.\033[1;39m"
#define CONSTRUCTOR "\033[1;33mBureaucraft default constructor called.\033[1;39m"

class Bureaucrat {
   public:
	Bureaucrat();
	Bureaucrat(std::string const &_name, int _grade);
	Bureaucrat(Bureaucrat const &cpy);
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const &rhs);
	Bureaucrat &operator++(void);
	Bureaucrat &operator--(void);
	static const int MinGrade = 1;
	static const int MaxGrade = 150;
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

   private:
	int grade;
	std::string const name;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif