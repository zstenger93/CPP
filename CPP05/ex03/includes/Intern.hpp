#ifndef INTERN_HPP
#define INTERN_HPP

#include "../includes/AForm.hpp"

class Intern {
   public:
	Intern();
	Intern(Intern const &cpy);
	~Intern();
	Intern &operator=(Intern const &rhs);
	AForm *makeForm(std::string const &formName, std::string const &target) const;

   private:
};

#endif