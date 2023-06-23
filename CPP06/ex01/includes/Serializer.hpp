#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <sys/_types/_uintptr_t.h>

#include <iostream>

#include "../includes/Data.h"

class Serializer {
   public:
	Serializer();
	Serializer(Serializer const &cpy);
	~Serializer();
	Serializer &operator=(Serializer const &rhs);
	uintptr_t serialize(Data *ptr);
	Data *deserialize(uintptr_t raw);
};

#endif