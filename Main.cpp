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
	/*LinkedList<int> list = LinkedList<int>();
	for (int i = 0; i < 10; i++)
		list.push_back(i);
	list.print_all();
	list.insert(0, 9);
	list.insert(1, 7);
	list.print_all();
	list.push_front(-1);
	list.push_front(-1);
	list.push_front(-1);
	list.update_all(-1, -2);
	list.remove_all(-2);
	list.print_all();*/

	//cout << endl << list[list.size() - 1] << endl;
	//list[list.size() - 1] = 0;
	//cout << list[list.size() - 1];
	//list.print_all();

	//cout << "\nКоличество элементов: " << list.size();
	//cout << endl << list.find(8) << endl;
	//for (auto i : list.find_all(-1))
	//{
	//	cout << i << " ";
	//}
	LinkedList<int>* list1 = new LinkedList<int>();
	for (int i = 1; i < 3; i++)
		list1->push_back(i);
	list1->print_all();
	list1->clear();
	list1->print_all();
	cout << endl << list1->size();
}