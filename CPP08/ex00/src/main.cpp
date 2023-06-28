#include "../includes/easyfind.hpp"

int main() {
	std::vector<int> vector;
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(5);

	std::list<int> list;
	list.push_back(10);
	list.push_back(20);
	list.push_back(30);
	list.push_back(40);
	list.push_back(50);
	std::array<int, 5> array = {100, 200, 300, 400, 500};

	std::cout << "Hector.. I mean Vector:" << std::endl;
	std::cout << easyfind(vector, 4) << std::endl;
	std::cout << "List:" << std::endl;
	std::cout << easyfind(list, 30) << std::endl;
	std::cout << "Array:" << std::endl;
	std::cout << easyfind(array, 200) << std::endl;
	std::cout << "Wrong:" << std::endl;
	std::cout << easyfind(vector, 8) << std::endl;
	std::cout << easyfind(vector, -8) << std::endl;

	return 0;
}