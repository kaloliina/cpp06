#include "../include/Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t uptr = reinterpret_cast<uintptr_t>(ptr); //reinterpret cast is used to convert a pointer of some data type into a pointer of another data type.
	return uptr;
}
Data* Serializer::deserialize(uintptr_t raw)
{
	Data *dataptr = reinterpret_cast<Data*>(raw);
	return dataptr;
}
