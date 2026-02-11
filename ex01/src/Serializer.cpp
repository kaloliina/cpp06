#include "../include/Serializer.hpp"

/*Reinterpret_cast operator is used to convert the pointer to any other type of pointer.
It does not perform any check whether the pointer converted is of the same type or not.
reinterpret_cast<new_type>(exp)
*/
uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t uptr = reinterpret_cast<uintptr_t>(ptr);
	return uptr;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *dataptr = reinterpret_cast<Data*>(raw);
	return dataptr;
}
