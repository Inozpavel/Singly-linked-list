#include <iostream>
#include "Person.h"

Person::Person(string surname, std::string name): _name(name), _surname(surname)
{
}

bool Person::operator==(Person& other)
{
	return _name == other._name && _surname == other._surname;
}

istream& operator>>(istream& in, Person& p)
{
	return in >> p._name >> p._surname;
}

ostream& operator<<(ostream& out, Person& p)
{
	return out << p._name + " " + p._surname;
}
