#ifndef PERSON_H
#define PERSON_H

#include <string>

using std::string;

class Person
{
private:
	string _name;
	string _surname;
public:
	Person(string surname, std::string name);
};

#endif

