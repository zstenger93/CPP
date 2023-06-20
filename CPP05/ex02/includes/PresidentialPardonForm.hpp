#ifndef PRESIDENTALPARDONFORM_HPP
#define PRESIDENTALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
   public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const &formTarget);
	PresidentialPardonForm(PresidentialPardonForm const &cpy);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
	~PresidentialPardonForm();
	virtual void execute(Bureaucrat const &executor) const;
	static const int gradeReq = 25;
	static const int execReq = 5;

   private:
	std::string target;
};

#endif