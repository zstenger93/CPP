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

void PmergeMe::insertionSort(std::vector<int>& seq) {
    for (size_t i = 1; i < seq.size(); i++) {
        int key = seq[i];
        int j = i - 1;

        while (j >= 0 && seq[j] > key) {
            seq[j + 1] = seq[j];
            j--;
        }

        seq[j + 1] = key;
    }
}