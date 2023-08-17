#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cmath>
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
#define AFTER "\033[1;4;32mAfter:\033[1;0;39m "
#define BEFORE "\033[1;4;33mBefore:\033[1;0;39m "
#define DEQUE_RESULT1 "\033[1;4;34mTime to process a range of\033[1;0;39m "
#define DEQUE_RESULT2 "\033[1;4;34m elements with std::deque:\033[1;0;39m "
#define VECTOR_RESULT1 "\033[1;4;34mTime to process a range of\033[1;0;39m "
#define VECTOR_RESULT2 " \033[1;4;34melements with std::vector is:\033[1;0;39m "
#define ALREADYSORTED "\033[1;31mThe input sequence is already sorted.\033[1;39m"
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
	int getNextJacobsthalNumber(int n);
	void printTime();

	// VECTOR
	void sort_Vector();
	void set_VectorSequence();
	void n2_Vector();
	void n2_SwapPairValues_Vector();
	// sort pairs
	void n2_RecursiveMergeSort_Vector(std::vector<std::pair<int, int> > &n2Sqnc, int left,
									  int right);
	void merge_Vector(std::vector<std::pair<int, int> > &n2Sqnc, int left, int mid, int right);
	void set_LargerAndSmallerFromN2sequence_Vector();
	// final sorting
	void n2_SortWithJacobsthalNumbers_Vector(std::vector<int> &targetVector,
											 std::vector<int> &insertionVector);
	unsigned long getUpperJacobsIndex_Vector(const std::vector<int> &insertionVector);
	unsigned long getNextUpperJacobsIndex_Vector(const std::vector<int> &insertionVector,
												 unsigned int upperJacobsIndex);
	void n2_BinaryInsert_Vector(std::vector<int> &targetVector, int value, int insertionRange);
	void printResult_Vector();

	// DEQUE
	void sort_Deque();
	void set_DequeSequence();
	void n2_Deque();
	void n2_SwapPairValues_Deque();
	// sort pairs
	void n2_RecursiveMergeSort_Deque(std::deque<std::pair<int, int> > &n2Sqnc, int left, int right);
	void merge_Deque(std::deque<std::pair<int, int> > &n2Sqnc, int left, int mid, int right);
	void set_LargerAndSmallerFromN2sequence_Deque();
	// final sorting
	void n2_SortWithJacobsthalNumbers_Deque(std::deque<int> &targetDeque,
											std::deque<int> &insertionDeque);
	unsigned long getUpperJacobsIndex_Deque(const std::deque<int> &insertionDeque);
	unsigned long getNextUpperJacobsIndex_Deque(const std::deque<int> &insertionDeque,
												unsigned int upperJacobsIndex);
	void n2_BinaryInsert_Deque(std::deque<int> &targetDeque, int value, int insertionRange);
	void printResult_Deque();

   private:
	int sequenceSize;
	char **sequence;

	clock_t startTime_Vector;
	std::vector<int> inputSequence_Vector;
	std::vector<std::pair<int, int> > n2Sequence_Vector;
	std::vector<int> smallerSequence_Vector;
	std::vector<int> largerSequence_Vector;
	std::vector<int> sortedSequence_Vector;
	clock_t endTime_Vector;

	clock_t startTime_Deque;
	std::deque<int> inputSequence_Deque;
	std::deque<std::pair<int, int> > n2_Sequence_Deque;
	std::deque<int> smallerSequence_Deque;
	std::deque<int> largerSequence_Deque;
	std::deque<int> sortedSequence_Deque;
	clock_t endTime_Deque;
};

#endif