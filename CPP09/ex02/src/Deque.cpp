#include "../includes/PmergeMe.hpp"

/*__________________________________________ FUNCTIONS __________________________________________*/

void PmergeMe::sort_Deque() {
	startTime_Deque = clock();
	n2_Deque();
	n2_SwapPairValues_Deque();
	n2_RecursiveMergeSort_Deque(n2_Sequence_Deque, 0, n2_Sequence_Deque.size() - 1);
	set_LargerAndSmallerFromN2sequence_Deque();
	n2_SortWithJacobsthalNumbers_Deque(largerSequence_Deque, smallerSequence_Deque);
	endTime_Deque = clock();
	// printResult_Deque();
}

void PmergeMe::n2_Deque() {
	std::deque<int>::iterator prevIt = inputSequence_Deque.begin(),
							  n2It = inputSequence_Deque.begin();

	for (; n2It < inputSequence_Deque.end(); n2It++) {
		if (std::distance(inputSequence_Deque.begin(), n2It) % 2 != 0)
			n2_Sequence_Deque.push_back(std::make_pair(*prevIt, *n2It));
		prevIt = n2It;
	}
	if (std::distance(inputSequence_Deque.begin(), n2It) % 2 != 0)
		n2_Sequence_Deque.push_back(std::make_pair(*prevIt, -1));
}

void PmergeMe::n2_SwapPairValues_Deque() {
	std::deque<std::pair<int, int> >::iterator n2It = n2_Sequence_Deque.begin();
	int temp;
	for (; n2It < n2_Sequence_Deque.end(); n2It++)
		if (n2It->second != -1)
			if (n2It->first > n2It->second) {
				temp = n2It->first;
				n2It->first = n2It->second;
				n2It->second = temp;
			}
}

void PmergeMe::merge_Deque(std::deque<std::pair<int, int> > &n2Sqnc, int left, int mid, int right) {
	int leftSize = mid - left + 1, rightSize = right - mid;

	std::deque<std::pair<int, int> > leftVectorPart(leftSize), rightVectorPart(rightSize);

	// copy stuff to righthalf and lefthalf
	for (int i = 0; i < leftSize; i++) leftVectorPart[i] = n2Sqnc[left + i];
	for (int j = 0; j < rightSize; j++) rightVectorPart[j] = n2Sqnc[mid + 1 + j];

	int i = 0, j = 0, leftCopy = left;

	// merging elemetns based on the 2nd value of pairs
	while (i < leftSize && j < rightSize) {
		if (leftVectorPart[i].second <= rightVectorPart[j].second) {
			n2Sqnc[leftCopy] = leftVectorPart[i++];
		} else
			n2Sqnc[leftCopy] = rightVectorPart[j++];
		leftCopy++;
	}
	while (i < leftSize) n2Sqnc[leftCopy++] = leftVectorPart[i++];
	while (j < rightSize) n2Sqnc[leftCopy++] = rightVectorPart[j++];
}

void PmergeMe::n2_RecursiveMergeSort_Deque(std::deque<std::pair<int, int> > &n2Sqnc, int left,
										   int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		n2_RecursiveMergeSort_Deque(n2Sqnc, left, mid);
		n2_RecursiveMergeSort_Deque(n2Sqnc, mid + 1, right);
		merge_Deque(n2Sqnc, left, mid, right);
	}
}

void PmergeMe::n2_SortWithJacobsthalNumbers_Deque(std::deque<int> &targetDeque,
												  std::deque<int> &insertionDeque) {
	unsigned long lowerJacobsIndex = 1;
	unsigned long upperJacobsIndex = getUpperJacobsIndex_Deque(insertionDeque);
	unsigned long iterationCount = upperJacobsIndex;

	targetDeque.insert(targetDeque.begin(), insertionDeque.at(0));
	for (; lowerJacobsIndex < insertionDeque.size();) {
		n2_BinaryInsert_Deque(targetDeque, insertionDeque.at(iterationCount),
							  upperJacobsIndex + lowerJacobsIndex - 1);
		if (iterationCount == lowerJacobsIndex) {
			lowerJacobsIndex = upperJacobsIndex + 1;
			upperJacobsIndex = getNextUpperJacobsIndex_Deque(insertionDeque, upperJacobsIndex);
			iterationCount = upperJacobsIndex;
		} else
			iterationCount--;
	}
	sortedSequence_Deque = targetDeque;
}

void PmergeMe::n2_BinaryInsert_Deque(std::deque<int> &targetDeque, int value, int insertionRange) {
	int lowerBound = 0, upperBound = insertionRange - 1;

	while (lowerBound <= upperBound) {
		int mid = lowerBound + (upperBound - lowerBound) / 2;

		if (targetDeque[mid] == value) {
			targetDeque.insert(targetDeque.begin() + mid + 1, value);
			return;
		} else if (targetDeque[mid] < value) {
			lowerBound = mid + 1;
		} else
			upperBound = mid - 1;
	}
	targetDeque.insert(targetDeque.begin() + lowerBound, value);
}

void PmergeMe::printResult_Deque() {
	std::deque<int>::iterator sortedIt = sortedSequence_Deque.begin();
	std::cout << AFTER << std::endl;
	for (; sortedIt < sortedSequence_Deque.end(); sortedIt++) std::cout << *sortedIt << " ";
	std::cout << std::endl;
}

/*___________________________________________ SETTERS ___________________________________________*/

void PmergeMe::set_DequeSequence() {
	for (int i = 1; i < sequenceSize + 1; i++) {
		for (size_t j = 0; j < std::strlen(sequence[i]); j++)
			if (std::string(NUMBERS).find(sequence[i][j]) == std::string::npos)
				throw std::logic_error(WRONGCHAR);
		inputSequence_Deque.push_back(std::atoi(sequence[i]));
	}
	int prevIndex = -1;
	std::deque<int>::iterator seqIt = inputSequence_Deque.begin();
	for (; seqIt < inputSequence_Deque.end(); seqIt++) {
		if (prevIndex != -1) {
			if (prevIndex < *seqIt)
				;
			else {
				std::deque<int>::iterator unSortedIt = inputSequence_Deque.begin();
				std::cout << BEFORE << std::endl;
				for (; unSortedIt < inputSequence_Deque.end(); unSortedIt++)
					std::cout << *unSortedIt << " ";
				std::cout << std::endl;
				return;
			}
		}
		prevIndex = *seqIt;
	}
	throw std::logic_error(ALREADYSORTED);
}

void PmergeMe::set_LargerAndSmallerFromN2sequence_Deque() {
	std::deque<std::pair<int, int> >::iterator n2It = n2_Sequence_Deque.begin();
	for (; n2It < n2_Sequence_Deque.end(); n2It++) {
		smallerSequence_Deque.push_back(n2It->first);
		if (n2It->second != -1) largerSequence_Deque.push_back(n2It->second);
	}
}

/*___________________________________________ GETTERS ___________________________________________*/

unsigned long PmergeMe::getUpperJacobsIndex_Deque(const std::deque<int> &insertionDeque) {
	if (insertionDeque.size() > 2) {
		return 2;
	} else
		return insertionDeque.size() - 1;
	return -42;
}

unsigned long PmergeMe::getNextUpperJacobsIndex_Deque(const std::deque<int> &insertionDeque,
													  unsigned int upperJacobsIndex) {
	if (getNextJacobsthalNumber(upperJacobsIndex + 1) > static_cast<int>(insertionDeque.size())) {
		return insertionDeque.size() - 1;
	} else
		return getNextJacobsthalNumber(upperJacobsIndex + 1) - 1;
	return -42;
}
