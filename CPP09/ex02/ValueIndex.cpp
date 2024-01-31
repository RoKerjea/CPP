#include "ValueIndex.hpp"

ValueIndex::ValueIndex(void) : _value(0), _index(0)
{
}

ValueIndex::ValueIndex(int value, unsigned long index) : _value(value), _index(index)
{
}

ValueIndex::ValueIndex(ValueIndex const &original)
{
	*this = original;
}

ValueIndex::~ValueIndex(void)
{}

ValueIndex &ValueIndex::operator=(ValueIndex const &rhs)
{
	if (this != &rhs)
	{
		this->_value = rhs._value;
		this->_index = rhs._index;
	}
	return *this;
}

int ValueIndex::getValue(void) const
{
	return this->_value;
}

unsigned long ValueIndex::getIndex(void) const
{
	return this->_index;
}

bool ValueIndex::operator<(ValueIndex const &rhs) const
{
	return (this->_value < rhs._value);
}

bool ValueIndex::operator>(ValueIndex const &rhs) const
{
	return (this->_value > rhs._value);
}

bool ValueIndex::operator==(ValueIndex const &rhs) const
{
	return (this->_value == rhs._value);
}
bool ValueIndex::operator!=(ValueIndex const &rhs) const
{
	return (this->_value != rhs._value);
}

std::ostream &operator<<(std::ostream &out, ValueIndex const &rhs)
{
	out << rhs.getValue();
	return out;
}