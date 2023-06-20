#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include <stdexcept>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
   public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const &formTarget);
	ShrubberyCreationForm(ShrubberyCreationForm const &cpy);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
	~ShrubberyCreationForm();
	virtual void execute(Bureaucrat const &executor) const;
	static const int gradeReq = 145;
	static const int execReq = 137;

   private:
	std::string target;
};

#endif