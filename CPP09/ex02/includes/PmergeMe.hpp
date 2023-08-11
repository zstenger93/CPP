#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <ctime>
#include <deque>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

#define RED "\033[1;31m"
#define END "\033[1;39m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"

#define BEFORE "\033[1;4;33mBefore:\033[1;0;39m "
#define AFTER "\033[1;4;32mAfter:\033[1;0;39m "
#define DEQUE_RESULT \
	"\033[1;4;34mTime to process a range of 5 elements with std::deque:\033[1;0;39m "
#define VECTOR_RESULT \
	"\033[1;4;34mTime to process a range of 5 elements with std::vector:\033[1;0;39m "

#define TOOSHORT "\033[1;31mThe sequence is too short, there is nothing to sort.\033[1;39m"
#define NOARG "\033[1;31mFord needs a sequence to be able to Johnson around.\033[1;39m"

class PmergeMe {
   public:
	PmergeMe();
	PmergeMe(int _sequenceSize, char **_sequence);
	PmergeMe(PmergeMe const &cpy);
	~PmergeMe();
	PmergeMe &operator=(PmergeMe const &cpy);

	void sortSequence();
	void setSequence();

	void sort_Vector();
	void set_VectorSequence();
	void n2_VectorSequence();
	void n2_Swap_VectorSequence();
	void set_LargerAndSmaller_VectorSequence();
	void mergeSmallerIntoLarger_VectorSequence();

	void sortDeque();
	void setDequeSequence();

   private:
	int sequenceSize;
	char **sequence;
	std::vector<int> inputSequence;

	std::vector<std::pair<int, int> > n2Sequence;

	std::vector<int> smallerSequence;
	std::vector<int> largerSequence;

	std::vector<int> sortedSequence;

	clock_t startTime;
	clock_t endTime;
};

#endif