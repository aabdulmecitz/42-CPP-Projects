#include "Serializer.hpp"
#include <cctype>
#include <cstdlib>
#include <cmath>

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr)
{
    return (uintptr_t)ptr;
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return (Data *)raw;
}

std::ostream& operator<<(std::ostream& os, const Serializer& sc)
{
	(void)sc;
	os << "Serializer";
	return os;
}

