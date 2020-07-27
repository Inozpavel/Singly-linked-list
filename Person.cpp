#include <iostream>
#include "Person.h"

Person::Person()
{
}

Person::Person(string surname, std::string name): _name(name), _surname(surname)
{
}

bool Person::operator==(Person& other)
{
	return _name == other._name && _surname == other._surname;
}

Person& Person::operator =(Person other)
{
	if (this == &other)
		return *this;
	_name = other._name;
	_surname = other._surname;
	return *this;
}

ostream& operator <<(ostream& out, Person& p)
{
	return out << p._name << ' ' << p._surname;
}
