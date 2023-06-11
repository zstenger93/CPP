#include "../includes/IMateriaSource.hpp"

/*____________________________ CONSTRUCTORS / DESTRUCTOR ____________________________*/

IMateriaSource::IMateriaSource() { std::cout << IM_CONSTRUCTOR << std::endl; }

IMateriaSource::IMateriaSource(const IMateriaSource &cpy) {
	std::cout << IM_COPYCON << std::endl;
	*this = cpy;
}

IMateriaSource::~IMateriaSource() { std::cout << IM_DESTRUCTOR << std::endl; }

/*________________________________ OPERATOR OVERLOAD ________________________________*/

IMateriaSource &IMateriaSource::operator=(IMateriaSource const &rhs) {
	(void)rhs;
	return *this;
}