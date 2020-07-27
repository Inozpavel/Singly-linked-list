#include <iostream>
#include "Person.h"

Person::Person(string surname, std::string name): _name(name), _surname(surname)
{
}

bool Person::operator==(Person& other)
{
	return _name == other._name && _surname == other._surname;
}

Person::operator string()
{
	return 	 _name + " " + _surname;
}
