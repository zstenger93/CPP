#include "../includes/Serializer.hpp"

/*__________________________________ CONSTRUCTORS / DESTRUCTOR __________________________________*/

Serializer::Serializer() {}
Serializer::Serializer(Serializer const &cpy) { *this = cpy; }
Serializer::~Serializer() {}

/*_____________________________________ OPERATOR OVERLOADS ______________________________________*/

Serializer &Serializer::operator=(Serializer const &rhs) {
	if (this != &rhs) *this = rhs;
	return *this;
}

/*__________________________________________ FUNCTIONS __________________________________________*/

uintptr_t Serializer::serialize(Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); }
Data *Serializer::deserialize(uintptr_t raw) { return reinterpret_cast<Data *>(raw); }
