#include "../includes/Form.hpp"

/*__________________________________ CONSTRUCTORS / DESTRUCTOR __________________________________*/

Form::Form() : formName(DEFORM), isSigned(false), gradeRequirement(42) {
	std::cout << formName << CONSTRUCTOR << std::endl;
}

Form::Form(std::string const &_formName, bool _isSigned, const int _gradeRequirement)
	: formName(_formName), isSigned(_isSigned), gradeRequirement(_gradeRequirement) {
	if (_gradeRequirement < MaxGrade) {
		throw(Form::FormGradeTooHighException());
	}
	if (_gradeRequirement > MinGrade) {
		throw(Form::FormGradeTooLowException());
	}
}

Form::Form(Form const &cpy)
	: formName(cpy.formName), isSigned(cpy.isSigned), gradeRequirement(cpy.gradeRequirement) {
	std::cout << formName << COPYCON << std::endl;
	*this = cpy;
}

Form::~Form() { std::cout << formName << DESTRUCTOR << std::endl; }

/*______________________________________ OPERATOR OVERLOAD ______________________________________*/

Form &Form::operator=(Form const &rhs) {
	std::cout << FORM << formName << ASSIGNMENT << std::endl;
	isSigned = rhs.isSigned;
	return *this;
}

std::ostream &operator<<(std::ostream &os, Form &form) {
	os << "The grade of " << form.Name() << " is: " << form.requirementGrade();
	if (form.isAlreadySigned() == false) os << " is not";
	os << " signed" << std::endl;
	return os;
}

/*___________________________________________ NESTED ____________________________________________*/

const char *Form::FormGradeTooLowException::what() const throw() { return F_GTL; }
const char *Form::FormGradeTooHighException::what() const throw() { return F_GTH; }
const char *Form::FormCannotBeSignedExecption::what() const throw() { return FCBS; }
const char *Form::FormIsAlreadySignedExecption::what() const throw() { return FIAS; }

/*___________________________________________ GETTERS ___________________________________________*/

int Form::requirementGrade() { return gradeRequirement; }
std::string const &Form::Name() const { return formName; }
bool Form::isAlreadySigned() { return isSigned; }

/*__________________________________________ FUNCTIONS __________________________________________*/

void Form::beSigned(Bureaucrat &bureaucrap) {
	if (isAlreadySigned() == true) throw(Form::FormIsAlreadySignedExecption());
	if (bureaucrap.getGrade() > gradeRequirement) throw(Form::FormCannotBeSignedExecption());
	std::cout << BUREAUCRAT << bureaucrap.getName() << SIGNED << formName << END << std::endl;
	isSigned = true;
}