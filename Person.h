#ifndef PERSON_H
#define PERSON_H

#include <string>

using std::string;
using std::istream;
using std::ostream;

class Person
{
private:

	string _name;
	string _surname;

public:
	Person();

	Person(string surname, string name);

	// Сравнение двух экзампляров класса Person на равность
	bool operator==(Person& other);

	// Для вывода экземпляра на консоль
	operator string();

	// Для копирования объектов
	Person& operator =(Person other);
};

#endif

