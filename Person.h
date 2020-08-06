#ifndef PERSON_H
#define PERSON_H

#include <string>

using std::string;
using std::ostream;

class Person
{
private:

	string _name;
	string _surname;

public:
	Person();

	Person(string surname, string name);

	// Сравнение двух экземпляров класса Person на равность
	bool operator==(Person& other);

	// Для копирования объектов
	Person& operator =(Person other);

	// Для вывода на консоль
	friend ostream& operator <<(ostream& out, Person& p);
};

#endif

