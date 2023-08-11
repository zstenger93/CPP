#include "../includes/PmergeMe.hpp"

int main(int argc, char **argv) {
	try {
		if (argc < 2) throw std::logic_error(NOARG);
		PmergeMe fordJohnson(argc - 1, argv);
		fordJohnson.setSequence();
		fordJohnson.sortSequence();
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
}