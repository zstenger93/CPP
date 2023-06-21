#include "../includes/RobotomyRequestForm.hpp"

/*__________________________________ CONSTRUCTORS / DESTRUCTOR __________________________________*/

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", false, RobotomyRequestForm::gradeReq),
	  target("Robotomy_target") {
	std::cout << AForm::Name() << CONSTRUCTOR << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy) : AForm(cpy) {
	target = cpy.target;
	std::cout << AForm::Name() << COPYCON << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &formTraget)
	: AForm("RobotomyRequestForm", false, RobotomyRequestForm::gradeReq), target(formTraget) {
	std::cout << AForm::Name() << " " << target << COPYCON << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << AForm::Name() << " " << target << DESTRUCTOR << std::endl;
}

/*_____________________________________ OPERATOR OVERLOADS ______________________________________*/

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	if (this != &rhs) {
		target = rhs.target;
		AForm::operator=(rhs);
	}
	std::cout << AForm::Name() << ASSIGNMENT << std::endl;
	return *this;
}

/*__________________________________________ FUNCTIONS __________________________________________*/

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (isAlreadySigned() == false) throw(AFormIsAlreadySignedExecption());
	if (executor.getGrade() > RobotomyRequestForm::execReq) throw(AFormCannotExecuteException());
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 1) throw(AFormRobotomyFailedException());
	std::cout << AForm::Name() << " " << target << ROBOTOMIZED << std::endl;
}
