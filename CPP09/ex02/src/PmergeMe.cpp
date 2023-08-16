#include "../includes/PmergeMe.hpp"

/*__________________________________ CONSTRUCTORS / DESTRUCTOR __________________________________*/

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(int _sequenceSize, char **_sequence)
	: sequenceSize(_sequenceSize), sequence(_sequence) {
	if (sequenceSize < 2) throw std::logic_error(TOOSHORT);
}
PmergeMe::PmergeMe(PmergeMe const &cpy) { *this = cpy; }
PmergeMe::~PmergeMe() {}

/*_____________________________________ OPERATOR OVERLOADS ______________________________________*/

PmergeMe &PmergeMe::operator=(const PmergeMe &cpy) {
	if (this != &cpy) {
		sequence = cpy.sequence;
		sequenceSize = cpy.sequenceSize;
	}
	return *this;
}

/*__________________________________________ FUNCTIONS __________________________________________*/

void PmergeMe::sortSequence() {
	sort_Vector();
	sort_Deque();
}

int PmergeMe::getNextJacobsthalNumber(int current) {
	int currentJacobsthalTerm = 0, previousJacobsthalTerm = 1, nextJacobsthalNumber = current;

	while (true) {
		nextJacobsthalNumber = 2 * currentJacobsthalTerm + previousJacobsthalTerm;
		currentJacobsthalTerm = previousJacobsthalTerm;
		previousJacobsthalTerm = nextJacobsthalNumber;
		if (nextJacobsthalNumber > current) return nextJacobsthalNumber;
	}
	return nextJacobsthalNumber;
}

/*___________________________________________ SETTERS ___________________________________________*/

void PmergeMe::setSequence() {
	set_VectorSequence();
	set_DequeSequence();
}
