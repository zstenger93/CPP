#include "../includes/Brain.hpp"

Brain::Brain() : IdeaIndex(0) { std::cout << "Default Brain" << CONSTRUCTOR << std::endl; }

Brain::Brain(Brain const &rhs) {
	std::cout << "Brain" << COPYCON << std::endl;
	*this = rhs;
}

Brain::~Brain() { std::cout << "Brain" << DESTRUCTOR << std::endl; }

/*
deep copy
duplicate the entire object
thread safe copies
ensures that the object hierarchy is stays the same
shallow -> only top level attributes are copied
*/
Brain &Brain::operator=(Brain const &rhs) {
	std::cout << "Brain" << ASSIGNMENT << std::endl;
	if (this != &rhs) {
		IdeaIndex = rhs.IdeaIndex;
		for (int i = 0; i < IdeaIndex; i++) ideas[i] = rhs.ideas[i];
		for (int i = IdeaIndex; i < IDEAS; i++) ideas[i].clear();
	}
	return *this;
}

void Brain::GenerateIdea(std::string const &idea) {
	if (idea.empty()) {
		std::cout << "Ideas cannot be empty" << std::endl;
		return;
	}
	if (IdeaIndex < 100) {
		ideas[IdeaIndex] = idea;
		IdeaIndex++;
	} else {
		std::cout << "Too many ideas" << std::endl;
	}
}

void Brain::PrintIdea() const {
	for (int i = 0; i < IDEAS; i++) {
		if (ideas[i].empty()) break;
		std::cout << ideas[i] << std::endl;
		system("make dj");
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
