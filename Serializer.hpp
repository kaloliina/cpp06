#pragma once
#include "Data.hpp"
#include <iostream>
#include <stdint.h>

/*uintptr is guaranteed to hold any object's address. It enhances the safety of code.*/
class Serializer
{
Serializer() = delete;
Serializer(const Serializer& copy) = delete;
Serializer& operator=(const Serializer& src) = delete;
~Serializer() = delete;

static uintptr_t serialize(Data* ptr)
{
	uintptr_t uptr = reinterpret_cast<uintptr_t>(ptr); //reinterpret cast is used to convert a pointer of some data type into a pointer of another data type.
	return uptr;
}
static Data* deserialize(uintptr_t raw)
{
	Data *dataptr = reinterpret_cast<Data*>(raw);
	return dataptr;
}
};
