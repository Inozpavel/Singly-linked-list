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
	Person(string surname, string name);

	// Сравнение двух экзампляров класса Person на равность
	bool operator==(Person& other);

	// Ввод данных в экземпляр
	friend istream& operator >>(istream& in, Person& p);

	// Вывод данных из экземпляра
	friend ostream& operator <<(ostream& out, Person& p);
};

#endif

