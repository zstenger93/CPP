#ifndef AAFORM_HPP
#define AAFORM_HPP

#include <cstdlib>
#include <exception>

#include "AFormDefines.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
   public:
	AForm();
	AForm(std::string const &_AformName, bool _isSigned, const int _gradeRequirement);
	AForm(AForm const &cpy);
	virtual ~AForm();
	AForm &operator=(AForm const &rhs);
	static const int MinGrade = 150;
	static const int MaxGrade = 1;
	std::string const &Name() const;
	void beSigned(Bureaucrat &bureaucrap);
	int requirementGrade() const;
	bool isAlreadySigned() const;
	virtual void execute(Bureaucrat const &executor) const = 0;

	class AFormGradeTooLowException : public std::exception {
	   public:
		const char *what() const throw();
	};

	class AFormGradeTooHighException : public std::exception {
	   public:
		const char *what() const throw();
	};

	class AFormCannotBeSignedExecption : public std::exception {
	   public:
		const char *what() const throw();
	};

	class AFormIsAlreadySignedExecption : public std::exception {
	   public:
		const char *what() const throw();
	};

	class AFormCannotExecuteException : public std::exception {
	   public:
		const char *what() const throw();
	};

	class AFormRobotomyFailedException : public std::exception {
	   public:
		const char *what() const throw();
	};

	class AFormCreationFailedException : public std::exception {
	   public:
		const char *what() const throw();
	};

	class AFormIsNullException : public std::exception {
	   public:
		const char *what() const throw();
	};

   private:
	std::string const formName;
	bool isSigned;				 // is the Aform signed
	const int gradeRequirement;	 // to execute
};

std::ostream &operator<<(std::ostream &os, AForm &form);

#endif