#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
   public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const &formTarget);
	RobotomyRequestForm(RobotomyRequestForm const &cpy);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
	~RobotomyRequestForm();
	virtual void execute(Bureaucrat const &executor) const;
	static const int gradeReq = 72;
	static const int execReq = 45;

   private:
	std::string target;
};

#endif