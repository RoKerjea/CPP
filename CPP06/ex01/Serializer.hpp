#pragma once

#include <iostream>
#include <stdint.h>

typedef struct	Data
{
	char	c;
	int		x;
}Data;

class	Serializer
{
	private:

	public:
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
};