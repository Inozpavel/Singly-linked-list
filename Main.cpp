#include <iostream>
#include "LinkedList.h"
#include "Person.h"
#include "Windows.h"

using namespace std;

void test();

unsigned SelectOption(string name, vector<string> options);
unsigned EnterPos(const string msg = "Введите позицию: ");
Person InputPerson();
void AddElement();
void RemoveElement();
void FindElement();
void UpdateElement();
void SwapElements();
void GetSize();


LinkedList<Person> list;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//setlocale(LC_ALL, "Russian");
	//test();
	cout << endl;
	while (true)
	{
		switch (SelectOption("Список доступных действий:", {
			"Добавить элемент",
			"Удалить элемент",
			"Найти элемент",
			"Изменить элемент",
			"Поменять два элемента местами",
			"Вывести длину списка",
			"Вывести список",
			"Очистить список",
			"Завершить программу"
			})) 
		{
		case 0:
			system("cls");
			break;

		case 1:
			AddElement();
			break;

		case 2:
			RemoveElement();
			break;

		case 3:
			FindElement();
			break;

		case 4:
			UpdateElement();
			break;

		case 5:
			SwapElements();
			break;

		case 6:
			cout << "Размер списка:\t" << list.size() << endl;
			break;

		case 7:
			list.print_all();
			break;

		case 8:
			list.clear();
			break;

		case 9:
			cout << "\nПрограмма завершила свою работу.";
			return 0;
		default:
			cout << "\n Некорректный ввод! Программа завершила свою работу.";
			return 0;
		}
		cout << endl;
	}
}

unsigned SelectOption(string description, vector<string> options)
{
	cout << description << endl;
	for (int i = 0; i < options.size(); i++)
		cout << '\t' << i + 1 << ".\t" << options[i] << endl;
	cout << "Ваш выбор: ";
	unsigned choise;
	cin >> choise;
	return choise;
}

unsigned EnterPos(const string msg)
{
	cout << msg;

	unsigned pos;
	cin >> pos;

	if (pos < 0 || pos >= list.size())
	{
		cout << "Некорретно указан индекс!\n";
		return list.NOT_FOUND;
	}
	return pos;
}

Person InputPerson()
{
	cout << "Введите имя и фамилию через пробел: ";
	string name, surname;
	cin >> name >> surname;
	Person person(surname, name);
	return person;
}

void AddElement()
{
	switch (SelectOption("Выберите место:", {
		"В начало",
		"В конец",
		"В произвольное место"
		}))
	{
	case 1:
		list.push_front(InputPerson());
		break;

	case 2:
		list.push_back(InputPerson());
		break;

	case 3:
		unsigned pos = EnterPos();
		if (pos!= list.NOT_FOUND)
			list.insert(pos, InputPerson());
		break;
	}
}

void RemoveElement()
{
	switch (SelectOption("Удалить элемент:", {
		"Первый",
		"Последний",
		"По значению"
		})) {
	case 1:
		list.remove_at(0);
		break;

	case 2:
		list.remove_at(list.size() - 1);
		break;

	case 3:
		switch (SelectOption("Выберите количество удалений:", {
			"Только первое найденное значение",
			"Все найденные значения" 
			}))
		{
		case 1:
			list.remove(InputPerson());
			break;

		case 2:
			list.remove_all(InputPerson());
			break;
		}
		break;
	}
}

void FindElement()
{
	unsigned nFound;
	vector<unsigned> founds;
	switch (SelectOption("Найти:", {
		"Первый",
		"Все" 
		}))
	{
	case 1:
		nFound = list.find(InputPerson());
		if (nFound == list.NOT_FOUND)
		{
			cout << "Элемент не найден.\n";
			break;
		}
		cout << "Элемент найден в [" << nFound << "]\n";
		break;

	case 2:
		founds = list.find_all(InputPerson());
		if (founds.empty())
		{
			cout << "Элемент не найден.\n";
			break;
		}
		cout << "Элемент найден на позициях:";
		for (auto& element : founds)
			cout << "[" << element << "] ";
		cout << endl;
		break;
	}
}

void UpdateElement()
{
	Person oldHuman, newHuman;
	switch (SelectOption("Изменить элемент по:", {
		"Значению",
		"Позиции"
		})) 
	{
	case 1:
		cout << "\tСтарое значение\n";
		oldHuman = InputPerson();
		cout << "\tНовое значение\n";
		newHuman = InputPerson();

		switch (SelectOption("Количество замен:", {
			"Заменить первый",
			"Заменить все" }))
		{
		case 1: 
			list.update(oldHuman, newHuman);
			break;
		case 2: 
			list.update_all(oldHuman, newHuman);
			break;
		}
		break;

	case 2:
		unsigned pos = EnterPos();
		if (pos != list.NOT_FOUND)
			list[pos] = InputPerson();
		break;
	}
}

void SwapElements()
{
	unsigned pos1 = EnterPos("Введите первую позицию: ");
	if (pos1 == list.NOT_FOUND)
		return;

	unsigned pos2 = EnterPos("Введите вторую позицию: ");

	if (pos2 != list.NOT_FOUND)
		list.swap(pos1, pos2);
}

void GetSize()
{
	cout << "Размер списка:\t" << list.size() << endl;
}

//void test()
//{
//	list.push_back(8);
//	list.push_back(860);
//	list.push_back(525);
//	list.push_front(111);
//	list.push_back(35);
//	list.push_front(123);
//	list.push_back(35);
//	list.push_front(456);
//	list.push_front(35);
//
//	cout << "Начальный список. ";
//	list.print_all();
//
//	cout << "Remove 860. ";
//	list.remove(860);
//	list.print_all();
//	cout << "Количество элементов: " << list.size() << endl << endl;
//
//	list.remove_all(35);
//	cout << "Remove_all 35. ";
//	list.print_all();
//	cout << "Количество элементов: " << list.size() << endl << endl;
//
//	list.remove(35);
//	cout << "Swap (0, list.size() - 1). ";
//	list.swap(0, list.size() - 1);
//	list.print_all();
//
//	cout << "Insert(2, 555). ";
//	list.insert(2, 555);
//	list.print_all();
//	cout << "Количество элементов: " << list.size() << endl << endl;
//
//	cout << "insert(4, 667).";
//	list.insert(4, 667);
//	list.print_all();
//
//	cout << "Количество элементов: " << list.size() << endl << endl;
//
//	auto count = list.update_all(667, 0);
//	cout << "list.update_all(667, 0). ";
//	list.print_all();
//
//	cout << "Количество замен: " << count << endl;
//	cout << "Количество элементов: " << list.size() << endl << endl;
//
//	auto element = 0;
//	list.print_all();
//	cout << "Позиция элемента " << element << " : " << list.find(element) << endl;
//	auto mas = list.find_all(element);
//	cout << "Позиция всех элементов " << element << " : ";
//	for (auto& i : mas)
//		cout << i << " ";
//	cout << endl;
//																							 
//	list.print_all();
//	cout << "\nИзмение элементов по [0] и [1] на 1. ";
//	list[0] = 1;
//	list[1] = 1;
//	list.print_all();
//
//	auto index = 1;
//	cout << "Элемент с индексом " << index << " : " << list[1] << endl;
//	
//	list.print_all();
//	cout << "\nТест++ и find для <int> : " << ++list[list.find(111)] << endl;
//	list.print_all();
//}