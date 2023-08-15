#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cstddef>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

#define RED "\033[1;31m"
#define END "\033[1;39m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"

#define NUMBERS "0123456789"
#define ALREADYSORTED "\033[1;31mThe input is already sorted.\033[1;39m"
#define AFTER "\033[1;4;32mAfter:\033[1;0;39m "
#define BEFORE "\033[1;4;33mBefore:\033[1;0;39m "
#define DEQUE_RESULT1 "\033[1;4;34mTime to process a range of "
#define DEQUE_RESULT2 "\033[1;4;34m elements with std::deque:\033[1;0;39m "
#define VECTOR_RESULT1 "\033[1;4;34mTime to process a range of\033[1;0;39m "
#define VECTOR_RESULT2 " \033[1;4;34melements with std::vector is:\033[1;0;39m "
#define WRONGCHAR "\033[1;31mThe input contains non numeric characters.\033[1;39m"
#define TOOSHORT "\033[1;31mThe sequence is too short, there is nothing to sort.\033[1;39m"
#define NOARG \
	"\033[1;31mFord needs a sequence of positive numbers to be able to Johnson around.\033[1;39m"

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
	void n2_Vector();
	void n2_Swap_Vector();
	void set_LargerAndSmaller_Vector();
	void mergeSmallerIntoLarger_Vector();
	void insertionSort_Vector(std::vector<int> &seq);
	void printResult_Vector();

	void sortDeque();
	void set_DequeSequence();

   private:
	int sequenceSize;
	char **sequence;

	std::vector<int> inputSequence_Vector;
	std::vector<std::pair<int, int> > n2Sequence_Vector;
	std::vector<int> smallerSequence_Vector;
	std::vector<int> largerSequence_Vector;
	std::vector<int> sortedSequence_Vector;

	clock_t startTime;
	clock_t endTime;
};

#endif