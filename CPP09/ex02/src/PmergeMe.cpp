#include "../includes/PmergeMe.hpp"

#include <cstddef>
#include <cstring>
#include <stdexcept>

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
	// sortDeque();
}

void PmergeMe::sort_Vector() {
	startTime = clock();
	n2_Vector();
	n2_Swap_Vector();
	set_LargerAndSmaller_Vector();
	insertionSort_Vector(smallerSequence_Vector);
	insertionSort_Vector(largerSequence_Vector);
	// std::sort(smallerSequence_Vector.begin(), smallerSequence_Vector.end());
	// std::sort(largerSequence_Vector.begin(), largerSequence_Vector.end());
	mergeSmallerIntoLarger_Vector();
	endTime = clock();
	print_VectorResult();
}

void PmergeMe::n2_Vector() {
	std::vector<int>::iterator prevIt = inputSequence_Vector.begin();
	std::vector<int>::iterator n2It = inputSequence_Vector.begin();
	for (; n2It < inputSequence_Vector.end(); n2It++) {
		if (std::distance(inputSequence_Vector.begin(), n2It) % 2 != 0)
			n2Sequence_Vector.push_back(std::make_pair(*prevIt, *n2It));
		prevIt = n2It;
	}
	if (std::distance(inputSequence_Vector.begin(), n2It) % 2 != 0)
		n2Sequence_Vector.push_back(std::make_pair(*prevIt, -1));
	// for (std::vector<std::pair<int, int> >::iterator n2It = n2Sequence_Vector.begin();
	// 	 n2It < n2Sequence_Vector.end(); n2It++)
	// 	std::cout << n2It->first << " " << n2It->second << std::endl;
}

void PmergeMe::n2_Swap_Vector() {
	std::vector<std::pair<int, int> >::iterator n2It = n2Sequence_Vector.begin();
	int temp;
	for (; n2It < n2Sequence_Vector.end(); n2It++) {
		// std::cout << "Before: " << n2It->first << " " << n2It->second << std::endl;
		if (n2It->second != -1)
			if (n2It->first > n2It->second) {
				temp = n2It->first;
				n2It->first = n2It->second;
				n2It->second = temp;
				// std::cout << "After: " << n2It->first << " " << n2It->second << std::endl;
			}
	}
	// for (n2It = n2Sequence_Vector.begin(); n2It != n2Sequence_Vector.end(); n2It++)
	// 	std::cout << n2It->first << " " << n2It->second << std::endl;
}

void PmergeMe::insertionSort_Vector(std::vector<int> &seq) {
	for (size_t i = 1; i < seq.size(); i++) {
		int prevIndex = i - 1, currentIndex = seq[i];

		while (prevIndex >= 0 && seq[prevIndex] > currentIndex) {
			seq[prevIndex + 1] = seq[prevIndex];
			prevIndex--;
		}
		seq[prevIndex + 1] = currentIndex;
	}
}

void PmergeMe::mergeSmallerIntoLarger_Vector() {
	sortedSequence_Vector.reserve(largerSequence_Vector.size() + smallerSequence_Vector.size());
	size_t indexLarge = 0, indexSmall = 0;

	while (indexLarge < largerSequence_Vector.size() &&
		   indexSmall < smallerSequence_Vector.size()) {
		if (largerSequence_Vector[indexLarge] < smallerSequence_Vector[indexSmall]) {
			sortedSequence_Vector.push_back(largerSequence_Vector[indexLarge]);
			indexLarge++;
		} else {
			sortedSequence_Vector.push_back(smallerSequence_Vector[indexSmall]);
			indexSmall++;
		}
	}
	// Insert remaining elements from largerSequence_Vector and smallerSequence_Vector
	while (indexLarge < largerSequence_Vector.size()) {
		sortedSequence_Vector.push_back(largerSequence_Vector[indexLarge]);
		indexLarge++;
	}
	while (indexSmall < smallerSequence_Vector.size()) {
		sortedSequence_Vector.push_back(smallerSequence_Vector[indexSmall]);
		indexSmall++;
	}
}

void PmergeMe::print_VectorResult() {
	std::vector<int>::iterator sortedIt = sortedSequence_Vector.begin();
	std::cout << AFTER << std::endl;
	for (; sortedIt < sortedSequence_Vector.end(); sortedIt++) std::cout << *sortedIt << " ";
	std::cout << std::endl;
	// std::cout << startTime << " " << endTime << std::endl;
	std::cout << VECTOR_RESULT1 << sequenceSize << VECTOR_RESULT2 << std::fixed
			  << std::setprecision(2)
			  << static_cast<double>(endTime - startTime) / (CLOCKS_PER_SEC / 1000000.0) << " us"
			  << std::endl;
}

/*___________________________________________ SETTERS ___________________________________________*/

void PmergeMe::setSequence() {
	set_VectorSequence();
	set_DequeSequence();
}

void PmergeMe::set_VectorSequence() {
	for (int i = 1; i < sequenceSize + 1; i++) {
		for (size_t j = 0; j < std::strlen(sequence[i]); j++)
			if (std::string(NUMBERS).find(sequence[i][j]) == std::string::npos)
				throw std::logic_error(WRONGCHAR);
		inputSequence_Vector.push_back(std::atoi(sequence[i]));
	}
	int prevIndex = -1;
	std::vector<int>::iterator seqIt = inputSequence_Vector.begin();
	for (; seqIt < inputSequence_Vector.end(); seqIt++) {
		if (prevIndex != -1) {
			if (prevIndex < *seqIt)
				;
			else {
				std::vector<int>::iterator unSortedIt = inputSequence_Vector.begin();
				std::cout << BEFORE << std::endl;
				for (; unSortedIt < inputSequence_Vector.end(); unSortedIt++)
					std::cout << *unSortedIt << " ";
				std::cout << std::endl;
				return;
			}
		}
		prevIndex = *seqIt;
	}
	throw std::logic_error(ALREADYSORTED);
	// for (std::vector<int>::iterator seqIt = inputSequence_Vector.begin(); seqIt <
	// inputSequence_Vector.end(); 	 seqIt++) 	std::cout << *seqIt << " "; std::cout << std::endl;
}

void PmergeMe::set_LargerAndSmaller_Vector() {
	std::vector<std::pair<int, int> >::iterator n2It = n2Sequence_Vector.begin();
	for (; n2It < n2Sequence_Vector.end(); n2It++) {
		smallerSequence_Vector.push_back(n2It->first);
		if (n2It->second != -1) largerSequence_Vector.push_back(n2It->second);
	}
}

void PmergeMe::set_DequeSequence() {}

/*___________________________________________ GETTERS ___________________________________________*/
