#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <exception>
#include <iostream>
#include <stdexcept>
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

   private:
	int sequenceSize;
	char **sequence;
};

#endif