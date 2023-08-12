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
	// sortDeque();
}

void PmergeMe::sort_Vector() {
	clock_t startTime = clock();
	n2_VectorSequence();
	n2_Swap_VectorSequence();
	set_LargerAndSmaller_VectorSequence();
	insertionSort(smallerSequence);
	insertionSort(largerSequence);
	// std::sort(smallerSequence.begin(), smallerSequence.end());
	// std::sort(largerSequence.begin(), largerSequence.end());
	mergeSmallerIntoLarger_VectorSequence();
	clock_t endTime = clock();
	std::vector<int>::iterator sortedIt = sortedSequence.begin();
	for (; sortedIt < sortedSequence.end(); sortedIt++) std::cout << *sortedIt << " ";
	std::cout << std::endl;
	std::cout << startTime << " " << endTime << std::endl;
	std::cout << std::fixed << std::setprecision(2)
			  << static_cast<double>(endTime - startTime) / (CLOCKS_PER_SEC / 1000000.0) << " us"
			  << std::endl;
}

void PmergeMe::n2_VectorSequence() {
	std::vector<int>::iterator prevIt = inputSequence.begin();
	std::vector<int>::iterator n2It = inputSequence.begin();
	for (; n2It < inputSequence.end(); n2It++) {
		if (std::distance(inputSequence.begin(), n2It) % 2 != 0)
			n2Sequence.push_back(std::make_pair(*prevIt, *n2It));
		prevIt = n2It;
	}
	if (std::distance(inputSequence.begin(), n2It) % 2 != 0)
		n2Sequence.push_back(std::make_pair(*prevIt, -1));
	// for (std::vector<std::pair<int, int> >::iterator n2It = n2Sequence.begin();
	// 	 n2It < n2Sequence.end(); n2It++)
	// 	std::cout << n2It->first << " " << n2It->second << std::endl;
}

void PmergeMe::n2_Swap_VectorSequence() {
	std::vector<std::pair<int, int> >::iterator n2It = n2Sequence.begin();
	int temp;
	for (; n2It < n2Sequence.end(); n2It++) {
		// std::cout << "Before: " << n2It->first << " " << n2It->second << std::endl;
		if (n2It->second != -1)
			if (n2It->first > n2It->second) {
				temp = n2It->first;
				n2It->first = n2It->second;
				n2It->second = temp;
				// std::cout << "After: " << n2It->first << " " << n2It->second << std::endl;
			}
	}
	// for (n2It = n2Sequence.begin(); n2It != n2Sequence.end(); n2It++)
	// 	std::cout << n2It->first << " " << n2It->second << std::endl;
}

void PmergeMe::mergeSmallerIntoLarger_VectorSequence() {
	sortedSequence.reserve(largerSequence.size() + smallerSequence.size());
	size_t indexLarge = 0, indexSmall = 0;

	while (indexLarge < largerSequence.size() && indexSmall < smallerSequence.size()) {
		if (largerSequence[indexLarge] < smallerSequence[indexSmall]) {
			sortedSequence.push_back(largerSequence[indexLarge]);
			indexLarge++;
		} else {
			sortedSequence.push_back(smallerSequence[indexSmall]);
			indexSmall++;
		}
	}
	// Insert remaining elements from largerSequence and smallerSequence
	while (indexLarge < largerSequence.size()) {
		sortedSequence.push_back(largerSequence[indexLarge]);
		indexLarge++;
	}
	while (indexSmall < smallerSequence.size()) {
		sortedSequence.push_back(smallerSequence[indexSmall]);
		indexSmall++;
	}
}

/*___________________________________________ SETTERS ___________________________________________*/

void PmergeMe::setSequence() {
	set_VectorSequence();
	setDequeSequence();
}

void PmergeMe::set_VectorSequence() {
	for (int i = 1; i < sequenceSize + 1; i++) inputSequence.push_back(std::atoi(sequence[i]));
	// for (std::vector<int>::iterator seqIt = inputSequence.begin(); seqIt < inputSequence.end();
	// 	 seqIt++)
	// 	std::cout << *seqIt << " ";
	// std::cout << std::endl;
}

void PmergeMe::set_LargerAndSmaller_VectorSequence() {
	std::vector<std::pair<int, int> >::iterator n2It = n2Sequence.begin();
	for (; n2It < n2Sequence.end(); n2It++) {
		smallerSequence.push_back(n2It->first);
		if (n2It->second != -1) largerSequence.push_back(n2It->second);
	}
}

void PmergeMe::setDequeSequence() {}

/*___________________________________________ GETTERS ___________________________________________*/
