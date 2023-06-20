#include "../includes/Bureaucrat.hpp"

#include "../includes/Form.hpp"

/*__________________________________ CONSTRUCTORS / DESTRUCTOR __________________________________*/

Bureaucrat::Bureaucrat() : name(DEFBURO), grade(42) {
	std::cout << name << CONSTRUCTOR << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &_name, int _grade) : name(_name) {
	if (_grade < MaxGrade) throw(Bureaucrat::GradeTooHighExecption());
	if (_grade > MinGrade) throw(Bureaucrat::GradeTooLowExecption());
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

const char *Bureaucrat::WrongDecrementExecption::what() const throw() { return WD; }
const char *Bureaucrat::WrongIncrementExecption::what() const throw() { return WI; }
const char *Bureaucrat::GradeTooLowExecption::what() const throw() { return GTL; }
const char *Bureaucrat::GradeTooHighExecption::what() const throw() { return GTH; }

/*___________________________________________ GETTERS ___________________________________________*/

int Bureaucrat::getGrade() const { return grade; }
std::string const &Bureaucrat::getName() const { return name; }

/*__________________________________________ FUNCTIONS __________________________________________*/

void Bureaucrat::IncrementGrade() {
	if (grade <= MaxGrade) throw(Bureaucrat::WrongIncrementExecption());
	std::cout << BUREAUCRAT << name << INCR << std::endl;
	grade--;
}

void Bureaucrat::DecrementGrade() {
	if (grade >= MinGrade) throw(Bureaucrat::WrongDecrementExecption());
	std::cout << BUREAUCRAT << name << DECR << std::endl;
	grade++;
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
	} catch (const std::exception &error) {
		std::cerr << form.Name() << RED << error.what() << END << std::endl;
	}
}