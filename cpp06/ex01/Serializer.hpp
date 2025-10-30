#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

typedef struct Data
{
	std::string	name;
	size_t		age;
	Data		*next;
}				Data;

class Serializer
{
private:
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    Serializer();
    ~Serializer();
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

};

std::ostream& operator<<(std::ostream& os, const Serializer& animal);

#endif