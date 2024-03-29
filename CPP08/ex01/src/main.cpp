#include <cstdlib>
#include <exception>

#include "../includes/Span.hpp"

static void AvailableTestCases() { std::cout << BAD_INPUT << TEST1 << TEST2 << TEST3 << std::endl; }

static int GetId(int argc, char **argv, int TestCaseId) {
	if (argc > 1) {
		int input = std::atoi(argv[1]);
		if (input < 1 || input > 10) return AvailableTestCases(), exit(1), 1;
		for (int i = 1; i >= 0; i++) {
			if (i == input) {
				TestCaseId = i;
				return TestCaseId;
			}
		}
	}
	return TestCaseId;
}

void TestShortestSpan() {
	try {
		Span span = Span(5);
		span.addNumber(54);
		span.addNumber(6);
		span.addNumber(25);
		span.addNumber(8);
		span.addNumber(14);
		std::cout << "The spansize is: " << span.size() << std::endl;
		std::cout << span.shortestSpan() << std::endl;
	} catch (const std::exception &error) {
		std::cout << RED << error.what() << END << std::endl;
	}
}

void TestLongestSpan() {
	try {
		Span span = Span(5);
		span.addNumber(54);
		span.addNumber(6);
		span.addNumber(25);
		span.addNumber(8);
		span.addNumber(14);
		std::cout << "The spansize is: " << span.size() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	} catch (const std::exception &error) {
		std::cout << RED << error.what() << END << std::endl;
	}
}

void TestBothSpan() {
	try {
		Span span = Span(5);
		span.addNumber(54);
		span.addNumber(6);
		span.addNumber(25);
		span.addNumber(8);
		span.addNumber(14);
		std::cout << "The spansize is: " << span.size() << std::endl;
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	} catch (const std::exception &error) {
		std::cout << RED << error.what() << END << std::endl;
	}
}

void TestTenK() {
	try {
		Span span = Span(10000);
		std::srand(std::time(NULL));
		for (int size = 0; size < 10000; size++) span.addNumber(rand() % RAND_MAX + 1);
		std::cout << "The spansize is: " << span.size() << std::endl;
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	} catch (const std::exception &error) {
		std::cout << RED << error.what() << END << std::endl;
	}
}

void TestSpanIsFull() {
	try {
		Span span = Span(5);
		span.addNumber(54);
		span.addNumber(6);
		span.addNumber(25);
		span.addNumber(8);
		span.addNumber(14);
		span.addNumber(93);
		unsigned int wtf = span.shortestSpan();
		std::cout << wtf << std::endl;
	} catch (const std::exception &error) {
		std::cout << RED << error.what() << END << std::endl;
	}
}
void TestNoSpan() {
	try {
		Span span = Span(1);
		span.addNumber(54);
		std::cout << "The spansize is: " << span.size() << std::endl;
		std::cout << span.shortestSpan() << std::endl;
	} catch (const std::exception &error) {
		std::cout << RED << error.what() << END << std::endl;
	}
}

void TestFillSpan() {
	try {
		Span span = Span(20000);
		span.fillSpan();
		std::cout << "The spansize is: " << span.size() << std::endl;
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	} catch (const std::exception &error) {
		std::cout << RED << error.what() << END << std::endl;
	}
}

void TestInvalidInput() {
	try {
		Span span = Span(0);
		span.addNumber(54);
		span.addNumber(6);
		span.addNumber(25);
		span.addNumber(8);
		span.addNumber(14);
		std::cout << "The spansize is: " << span.size() << std::endl;
		std::cout << span.shortestSpan() << std::endl;
	} catch (const std::exception &error) {
		std::cout << RED << error.what() << END << std::endl;
	}
}

void TestDumbFill() {
	int start = -10001, end = 10000, size = start - end - 2;
	try {
		Span span = Span(size);
		std::vector<int> range;
		std::srand(std::time(NULL));
		unsigned long long strt = getCurrentTimeMicros();
		for (int i = 0; i < 20000; i++) range.push_back(rand() % RAND_MAX + 1);
		span.fillSpanDumbWay(range.begin(), range.end());
		unsigned long long nd = getCurrentTimeMicros();
		unsigned long long ms = nd - strt;
		std::cout << "Filling up the span took: " << ms << "ms." << std::endl;
		std::cout << "The spansize is: " << span.size() << std::endl;
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	} catch (const std::exception &error) {
		std::cout << RED << error.what() << END << std::endl;
	}
}

void TestSmartFill() {
	int start = -10001, end = 10000, size = start - end - 2;
	try {
		Span span = Span(size);
		span.fillSpanSmartWay(start, end);
		std::cout << "The spansize is: " << span.size() << std::endl;
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	} catch (const std::exception &error) {
		std::cout << RED << error.what() << END << std::endl;
	}
}

int main(int argc, char **argv) {
	int TestCaseId = GetId(argc, argv, 0);

	switch (TestCaseId) {
		case 1:
			TestShortestSpan();
			break;
		case 2:
			TestLongestSpan();
			break;
		case 3:
			TestBothSpan();
			break;
		case 4:
			TestTenK();
			break;
		case 5:
			TestSpanIsFull();
			break;
		case 6:
			TestNoSpan();
			break;
		case 7:
			TestFillSpan();
			break;
		case 8:
			TestInvalidInput();
			break;
		case 9:
			TestSmartFill();
			break;
		case 10:
			TestDumbFill();
			break;
		default:
			AvailableTestCases();
			break;
	}
	return 0;
}