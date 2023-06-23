#include "../includes/Serializer.hpp"

int main() {
	uintptr_t raw;
	Serializer takeDataDo;
	Data *dataToSerialize = new Data;
	Data *deserializedData;

	dataToSerialize->str = "nani?!";
	dataToSerialize->c = 'c';
	dataToSerialize->i = 4;
	raw = takeDataDo.serialize(dataToSerialize);
	std::cout << "raw value: " << raw << std::endl;
	deserializedData = takeDataDo.deserialize(raw);
	std::cout << deserializedData->str << std::endl;
	std::cout << deserializedData->c << std::endl;
	std::cout << deserializedData->i << std::endl;

	delete dataToSerialize;
	return 0;
}