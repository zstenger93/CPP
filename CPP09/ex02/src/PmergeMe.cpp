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

void PmergeMe::printTime() {
	std::cout << std::endl
			  << VECTOR_RESULT1 << sequenceSize << VECTOR_RESULT2 << std::fixed
			  << std::setprecision(2)
			  << static_cast<double>(endTime_Vector - startTime_Vector) /
					 (CLOCKS_PER_SEC / 1000000.0)
			  << " us" << std::endl;
	std::cout << std::endl
			  << DEQUE_RESULT1 << sequenceSize << DEQUE_RESULT2 << std::fixed
			  << std::setprecision(2)
			  << static_cast<double>(endTime_Deque - startTime_Deque) / (CLOCKS_PER_SEC / 1000000.0)
			  << " us" << std::endl;
}

/*___________________________________________ SETTERS ___________________________________________*/

void PmergeMe::setSequence() {
	set_VectorSequence();
	set_DequeSequence();
	std::vector<int>::iterator unSortedIt = inputSequence_Vector.begin();
	std::cout << BEFORE << std::endl;
	for (; unSortedIt < inputSequence_Vector.end(); unSortedIt++) std::cout << *unSortedIt << " ";
	std::cout << std::endl;
}
