#include "../includes/AForm.hpp"

/*__________________________________ CONSTRUCTORS / DESTRUCTOR __________________________________*/

AForm::AForm() : formName(DEFORM), isSigned(false), gradeRequirement(42) {
	std::cout << formName << CONSTRUCTOR << std::endl;
}

AForm::AForm(std::string const &_formName, bool _isSigned, const int _gradeRequirement)
	: formName(_formName), isSigned(_isSigned), gradeRequirement(_gradeRequirement) {
	if (_gradeRequirement < MaxGrade) {
		throw(AForm::AFormGradeTooHighException());
	}
	if (_gradeRequirement > MinGrade) {
		throw(AForm::AFormGradeTooLowException());
	}
}

AForm::AForm(AForm const &cpy)
	: formName(cpy.formName), isSigned(cpy.isSigned), gradeRequirement(cpy.gradeRequirement) {
	std::cout << formName << COPYCON << std::endl;
	*this = cpy;
}

AForm::~AForm() { std::cout << formName << DESTRUCTOR << std::endl; }

/*______________________________________ OPERATOR OVERLOAD ______________________________________*/

AForm &AForm::operator=(AForm const &rhs) {
	std::cout << FORM << formName << ASSIGNMENT << std::endl;
	isSigned = rhs.isSigned;
	return *this;
}

std::ostream &operator<<(std::ostream &os, AForm &Aform) {
	os << "The grade of " << Aform.Name() << " is: " << Aform.requirementGrade();
	if (Aform.isAlreadySigned() == false) os << " is not";
	os << " signed" << std::endl;
	return os;
}

/*___________________________________________ NESTED ____________________________________________*/

const char *AForm::AFormGradeTooLowException::what() const throw() { return F_GTL; }
const char *AForm::AFormGradeTooHighException::what() const throw() { return F_GTH; }
const char *AForm::AFormCannotBeSignedExecption::what() const throw() { return FCBS; }
const char *AForm::AFormIsAlreadySignedExecption::what() const throw() { return FIAS; }
const char *AForm::AFormRobotomyFailedException::what() const throw() { return RFE; }
const char *AForm::AFormCreationFailedException::what() const throw() { return FCF; }
const char *AForm::AFormCannotExecuteException::what() const throw() { return CEE; }
const char *AForm::AFormIsNullException::what() const throw() { return ISNULL; }

/*___________________________________________ GETTERS ___________________________________________*/

int AForm::requirementGrade() const { return gradeRequirement; }
std::string const &AForm::Name() const { return formName; }
bool AForm::isAlreadySigned() const { return isSigned; }

/*__________________________________________ FUNCTIONS __________________________________________*/

void AForm::beSigned(Bureaucrat &bureaucrap) {
	if (isAlreadySigned() == true) throw(AForm::AFormIsAlreadySignedExecption());
	if (bureaucrap.getGrade() > gradeRequirement) throw(AForm::AFormCannotBeSignedExecption());
	std::cout << BUREAUCRAT << bureaucrap.getName() << SIGNED << formName << END << std::endl;
	isSigned = true;
}
