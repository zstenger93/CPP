#include "../includes/ShrubberyCreationForm.hpp"

/*__________________________________ CONSTRUCTORS / DESTRUCTOR __________________________________*/

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", false, ShrubberyCreationForm::gradeReq),
	  target("Shrubbery_target") {
	std::cout << AForm::Name() << CONSTRUCTOR << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy) : AForm(cpy) {
	target = cpy.target;
	std::cout << AForm::Name() << COPYCON << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &formTarget)
	: AForm("ShrubberyCreationForm", false, ShrubberyCreationForm::gradeReq),
	  target(formTarget + "_shrubbery") {
	std::cout << AForm::Name() << " " << target << COPYCON << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << AForm::Name() << " " << target << DESTRUCTOR << std::endl;
}

/*_____________________________________ OPERATOR OVERLOADS ______________________________________*/

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	if (this != &rhs) {
		target = rhs.target;
		AForm::operator=(rhs);
	}
	std::cout << AForm::Name() << ASSIGNMENT << std::endl;
	return *this;
}

/*__________________________________________ FUNCTIONS __________________________________________*/

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	std::string tree =
		"           6666\n"
		"         666 6666\n"
		"        66 I AM 66\n"
		"        66 GROOT 66\n"
		"         66 ಥ⁠‿⁠ಥ 6\n"
		"          6666666\n"
		"            666\n"
		"            666\n"
		"            666\n"
		"____________666____________\n";

	if (isAlreadySigned() == false) throw(AFormIsAlreadySignedExecption());
	if (executor.getGrade() > ShrubberyCreationForm::execReq){
		throw(AFormCannotExecuteException());
	}
	std::ofstream kibaszottfa(target.c_str());
	if (!kibaszottfa) throw std::runtime_error(CANTOPEN);
	kibaszottfa << tree;
	std::cout << GROOT << std::endl;
}
