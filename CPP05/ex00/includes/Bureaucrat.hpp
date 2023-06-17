#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define END "\033[1;39m"

class Bureaucrat {
   public:
	Bureaucrat();
	Bureaucrat(std::string const &name);
	Bureaucrat(Bureaucrat const &cpy);
	~Bureaucrat();
	Bureaucrat &operator<<(Bureaucrat const &rhs);
	std::string const &getName() const;
	void getGrade();  // lowest 1 highest is 150

   protected:
	int grade;
	std::string const name;
};

#endif