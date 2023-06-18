#include "../includes/Bureaucrat.hpp"

/*__________________________________ CONSTRUCTORS / DESTRUCTOR __________________________________*/

Bureaucrat::Bureaucrat() : name(DEFBURO), grade(150) { std::cout << CONSTRUCTOR << std::endl; }

Bureaucrat::Bureaucrat(std::string const &_name, int _grade) : name(_name) {
	if (grade > MaxGrade)
		throw (Bureaucrat::GradeTooLowExecption());
	else if (grade < MinGrade)
		throw (Bureaucrat::GradeTooLowExecption());
	grade = _grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &cpy) {
	std::cout << BUREAUCRAT << name << COPYCON << std::endl;
	*this = cpy;
}

Bureaucrat::~Bureaucrat() { std::cout << DESTRUCTOR << std::endl; }

/*______________________________________ OPERATOR OVERLOAD ______________________________________*/

Bureaucrat &Bureaucrat::operator++(void) { return grade--, *this; }

Bureaucrat &Bureaucrat::operator--(void) { return grade++, *this; }

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
	std::cout << BUREAUCRAT << name << ASSIGNMENT << std::endl;
	grade = rhs.grade;
	return *this;
}

/*___________________________________________ NESTED ____________________________________________*/

const char *Bureaucrat::GradeTooLowExecption::what() const throw() { return GTL; }

const char *Bureaucrat::GradeTooHighExecption::what() const throw() { return GTH; }

/*__________________________________________ FUNCTIONS __________________________________________*/

int Bureaucrat::getGrade() const { return grade; }

std::string const &Bureaucrat::getName() const { return name; }

void Bureaucrat::IncrementGrade() {
	if (grade >= MaxGrade) throw(Bureaucrat::GradeTooHighExecption());
	std::cout << BUREAUCRAT << name << INCR << std::endl;
	grade++;
}

void Bureaucrat::DecrementGrade() {
	if (grade <= MinGrade) throw(Bureaucrat::GradeTooLowExecption());
	std::cout << BUREAUCRAT << name << DECR << std::endl;
	grade--;
}