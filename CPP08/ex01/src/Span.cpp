#include "../includes/Span.hpp"

/*__________________________________ CONSTRUCTORS / DESTRUCTOR __________________________________*/

Span::Span() : spanSize(0) {}

Span::Span(Span const &cpy) {
	this->spanSize = cpy.spanSize;
	this->numbers = cpy.numbers;
}

Span::Span(const unsigned int &nums) : spanSize(nums) {
	if (spanSize < 1) throw spanInvalidSizeException();
}
Span::~Span() {}

/*_____________________________________ OPERATOR OVERLOADS ______________________________________*/

Span &Span::operator=(Span const &rhs) {
	if (this != &rhs) {
		this->spanSize = rhs.spanSize;
		this->numbers = rhs.numbers;
	}
	return *this;
}

/*_______________________________________ NESTED CLASSES ________________________________________*/

const char *Span::noSpanFoundException::what() const throw() { return NSPF; }
const char *Span::spanAlreadyFullException::what() const throw() { return SPAF; }
const char *Span::spanInvalidSizeException::what() const throw() { return INVS; }

/*__________________________________________ FUNCTIONS __________________________________________*/

void Span::addNumber(int number) {
	if (spanSize == numbers.size()) throw(spanAlreadyFullException());
	numbers.push_back(number);
}

void Span::fillSpan() {
	std::srand(std::time(NULL));
	unsigned long long start = getCurrentTimeMicros();
	for (unsigned long int i = 0; i < spanSize; i++) numbers.push_back(rand() % RAND_MAX + 1);
	unsigned long long end = getCurrentTimeMicros();
	unsigned long long ms = end - start;
	std::cout << "Filling up the span took: " << ms << "ms." << std::endl;
}

void Span::fillSpanDumbWay(std::vector<int>::iterator const &startVal,
						   std::vector<int>::iterator const &endVal) {
	if (numbers.size() + std::distance(startVal, endVal) > spanSize) {
		std::cout << "Error: Invalid range! Start value must be less than or equal to end value."
				  << std::endl;
		return;
	}
	std::srand(std::time(NULL));
	// unsigned long long start = getCurrentTimeMicros();
	numbers.reserve(endVal - startVal + 1);	 // Reserve space to avoid reallocations
	numbers.insert(numbers.end(), startVal, endVal);
	// unsigned long long end = getCurrentTimeMicros();
	// unsigned long long ms = end - start;
	// std::cout << "Filling up the span took: " << ms << "ms." << std::endl;
}

void Span::fillSpanSmartWay(int startValue, int endValue) {
	if (startValue > endValue) {
		std::cout << "Error: Invalid range! Start value must be less than or equal to end value."
				  << std::endl;
		return;
	}
	unsigned long long start = getCurrentTimeMicros();
	numbers.reserve(endValue - startValue + 1);	 // Reserve space to avoid reallocations
	int i = startValue + 1;
	for (; i < endValue; ++i) numbers.insert(numbers.end(), rand() % RAND_MAX + 1);
	unsigned long long end = getCurrentTimeMicros();
	unsigned long long ms = end - start;
	std::cout << "Filling up the span took: " << ms << "ms." << std::endl;
}

int Span::size() { return numbers.size(); }

unsigned int Span::shortestSpan() {
	if (numbers.size() < 2) throw noSpanFoundException();
	std::vector<int> tmp = numbers;
	std::sort(tmp.begin(), tmp.end());
	unsigned int shortest = *(tmp.begin() + 1) - *(tmp.begin());
	for (std::vector<int>::iterator i = tmp.begin(); i < tmp.end(); i++)
		if ((unsigned int)(*(i + 1) - *i) < shortest) shortest = *(i + 1) - *i;
	std::cout << "\033[1;32mThe shortest span is: \033[0;39m";
	return shortest;
}

unsigned int Span::longestSpan() {
	if (numbers.size() < 2) throw noSpanFoundException();
	std::cout << "\033[1;32mThe longest span is: \033[0;39m";
	return *std::max_element(numbers.begin(), numbers.end()) -
		   *std::min_element(numbers.begin(), numbers.end());
}

#include <sys/time.h>

// Function to get the current time in microseconds on macOS
unsigned long long getCurrentTimeMicros() {
	timeval tv;
	gettimeofday(&tv, NULL);

	unsigned long long currentTimeMicros = static_cast<unsigned long long>(tv.tv_sec) * 1000;
	currentTimeMicros += static_cast<unsigned long long>(tv.tv_usec);

	return currentTimeMicros;
}