#include "../includes/Bureaucrat.hpp"

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

/*______________________________________ OPERATOR OVERLOAD ______________________________________*/

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
	std::cout << BUREAUCRAT << name << ASSIGNMENT << std::endl;
	grade = rhs.grade;
	return *this;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat) {
	os << "The grade of " << bureaucrat.getName() << " is: " << bureaucrat.getGrade() << std::endl;
	return os;
}

/*___________________________________________ NESTED ____________________________________________*/

const char *Bureaucrat::WrongDecrement::what() const throw() { return WD; }

const char *Bureaucrat::WrongIncrement::what() const throw() { return WI; }

const char *Bureaucrat::GradeTooLowExecption::what() const throw() { return GTL; }

const char *Bureaucrat::GradeTooHighExecption::what() const throw() { return GTH; }

/*__________________________________________ FUNCTIONS __________________________________________*/

int Bureaucrat::getGrade() const { return grade; }

std::string const &Bureaucrat::getName() const { return name; }

void Bureaucrat::IncrementGrade() {
	if (grade <= MaxGrade) throw(Bureaucrat::WrongIncrement());
	std::cout << BUREAUCRAT << name << INCR << std::endl;
	grade--;
}

void Bureaucrat::DecrementGrade() {
	if (grade >= MinGrade) throw(Bureaucrat::WrongDecrement());
	std::cout << BUREAUCRAT << name << DECR << std::endl;
	grade++;
}