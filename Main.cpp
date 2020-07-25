#include <iostream>
#include "LinkedList.h"
#include "Person.h"

using namespace std;

void test();

int main()
{
	setlocale(LC_ALL, "Russian");
	test();
}

void test()
{
	LinkedList<int> list;

	list.push_back(8);
	list.push_back(860);
	list.push_back(525);
	list.push_front(111);
	list.push_back(35);
	list.push_front(123);
	list.push_back(35);
	list.push_front(456);
	list.push_front(35);

	cout << "Начальный список. ";
	list.print_all();

	cout << "Remove 860. ";
	list.remove(860);
	list.print_all();
	cout << "Количество элементов: " << list.size() << endl << endl;

	list.remove_all(35);
	cout << "Remove_all 35. ";
	list.print_all();
	cout << "Количество элементов: " << list.size() << endl << endl;

	list.remove(35);
	cout << "Swap (0, list.size() - 1). ";
	list.swap(0, list.size() - 1);
	list.print_all();

	cout << "Insert(2, 555). ";
	list.insert(2, 555);
	list.print_all();
	cout << "Количество элементов: " << list.size() << endl << endl;

	cout << "insert(4, 667).";
	list.insert(4, 667);
	list.print_all();

	cout << "Количество элементов: " << list.size() << endl << endl;

	auto count = list.update_all(667, 0);
	cout << "list.update_all(667, 0). ";
	list.print_all();

	cout << "Количество замен: " << count << endl;
	cout << "Количество элементов: " << list.size() << endl << endl;

	auto element = 0;
	list.print_all();
	cout << "Позиция элемента " << element << " : " << list.find(element) << endl;
	auto mas = list.find_all(element);
	cout << "Позиция всех элементов " << element << " : ";
	for (auto& i : mas)
		cout << i << " ";
	cout << endl;
																							 
	list.print_all();
	cout << "\nИзмение элементов по [0] и [1] на 1. ";
	list[0] = 1;
	list[1] = 1;
	list.print_all();

	auto index = 1;
	cout << "Элемент с индексом " << index << " : " << list[1] << endl;
	
	list.print_all();
	cout << "\nТест++ и find для <int> : " << ++list[list.find(111)] << endl;
	list.print_all();
}