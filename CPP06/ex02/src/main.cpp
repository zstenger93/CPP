#include "../includes/Identify.hpp"

int main() {
	std::srand(std::time(NULL));
	Identify identity;
	Base *ptr = identity.generate();
	Base *tmp = identity.generate();
	Base &ref = *tmp;
	Base badCastTest;
	Base *iAmNull = NULL;

	identity.identify(ptr);
	identity.identify(ref);

	identity.identify(iAmNull);
	identity.identify(badCastTest);
	delete ptr;
	delete tmp;
	return 0;
}
