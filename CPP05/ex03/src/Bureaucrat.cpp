#include "../includes/Bureaucrat.hpp"

#include <exception>

#include "../includes/AForm.hpp"

/*__________________________________ CONSTRUCTORS / DESTRUCTOR __________________________________*/

Bureaucrat::Bureaucrat() : name(DEFBURO), grade(42) {
	std::cout << name << CONSTRUCTOR << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &_name, int _grade) : name(_name) {
	std::cout << name << CONSTRUCTOR << std::endl;
	if (_grade < MaxGrade) throw(Bureaucrat::GradeTooHighException());
	if (_grade > MinGrade) throw(Bureaucrat::GradeTooLowException());
	grade = _grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &cpy) {
	std::cout << BUREAUCRAT << name << COPYCON << std::endl;
	*this = cpy;
}

Bureaucrat::~Bureaucrat() { std::cout << name << DESTRUCTOR << std::endl; }

/*_____________________________________ OPERATOR OVERLOADS ______________________________________*/

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
	std::cout << BUREAUCRAT << name << ASSIGNMENT << std::endl;
	grade = rhs.grade;
	return *this;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat) {
	os << "The grade of " << bureaucrat.getName() << " is: " << bureaucrat.getGrade() << std::endl;
	return os;
}

/*_______________________________________ NESTED CLASSES ________________________________________*/

const char *Bureaucrat::WrongDecrementException::what() const throw() { return WD; }
const char *Bureaucrat::WrongIncrementException::what() const throw() { return WI; }
const char *Bureaucrat::GradeTooLowException::what() const throw() { return GTL; }
const char *Bureaucrat::GradeTooHighException::what() const throw() { return GTH; }

/*___________________________________________ GETTERS ___________________________________________*/

int Bureaucrat::getGrade() const { return grade; }
std::string const &Bureaucrat::getName() const { return name; }

/*__________________________________________ FUNCTIONS __________________________________________*/

void Bureaucrat::IncrementGrade() {
	if (grade <= MaxGrade) throw(Bureaucrat::WrongIncrementException());
	std::cout << BUREAUCRAT << name << INCR << std::endl;
	grade--;
}

void Bureaucrat::DecrementGrade() {
	if (grade >= MinGrade) throw(Bureaucrat::WrongDecrementException());
	std::cout << BUREAUCRAT << name << DECR << std::endl;
	grade++;
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
	} catch (const std::exception &error) {
		std::cerr << form.Name() << RED << error.what() << END << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout << BUREAUCRAT << name << " executed " << form.Name() << std::endl;
	} catch (std::exception &error) {
		std::cout << BUREAUCRAT << name << " cannot execute " << form.Name() << " because "
				  << error.what() << std::endl;
	}
}