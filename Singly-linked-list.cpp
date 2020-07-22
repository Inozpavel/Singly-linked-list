#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Узел списка, содержит данные и указатель на следующий элемент
template <typename T>
struct Node 
{
	T data;
	Node* next;
	Node(T data, Node* next = nullptr) : data(data), next(next) {}
};


/* Структура связного списка:
	head -> node_1 -> ... -> node_n -> nullptr
	head так же node, но самый первый
	node указывающий на nullptr называется хвостом (tail)
	Linked List (связный список) будем называть просто списком или LL
	LL[0] = head
	LL[1] = head.next
	LL[2] = head.next.next
*/
template <typename T>
class LinkedList 
{
private:
	Node<T>* _head;
	Node<T>* _end;
	unsigned _nodesСount;

	// Удаляет элемент, сохраняя целосность списка
	// previous = nullptr для удаления головного объекта
	void remove_node(Node<T>* node, Node<T>* previous)
	{
		if (previous != nullptr)
			previous->next = node->next;
		delete node;
	}
	// Ищет элемент с начаал списка по индексу
	// В стучае успеха возвращает указатель на него, иначе nullptr
	Node<T>* _get_element(unsigned index)
	{
		if (index >= _nodesСount)
			return nullptr;
		Node<T>* current = _head;
		unsigned i = 0;
		while (current != nullptr && i < index)
		{
			current = current->next;
			++i;
		}
		return current;
	}

public:
	LinkedList() : _head(nullptr), _nodesСount(0)
	{
	}

	// Добавление элемента на указанную позицию
	void insert(T element, unsigned pos)
	{
		if (_nodesСount == 0)
			_head = new Node<T>(element);
		else
		{
			if (pos == 0)
				_head = new Node<T>(element, _head);
			else
			{
				auto current = _get_element(pos - 1);
				current->next = new Node<T>(element, current->next);
			}
		}
		_nodesСount++;
	}

	// Добавление элемента в конец
	void push_back(T element) 
	{
		insert(element, _nodesСount);
	}

	// Добавление элемента в начало
	void push_front(T element) 
	{
		insert(element, 0);
	}

	// Удаление одного элемента по значению value
	// Вернёт true в случае успеха (нашёл)
	// NotImplemented
	bool remove(T value) 
	{
		return false;
	}

	// Удаление элемента на позиции pos
	// NotImplemented
	void remove_at(unsigned pos) 
	{

	}

	// Удаление всех элементов со значением value
	// Вернёт количество удалённых элементов
	// NotImplemented
	unsigned remove_all(T value) 
	{
		return 0;
	}

	// Поиск одного элемента по значению
	// В случае успеха вернёт позицию первого элемента
	unsigned find(T value, unsigned start_pos = 0) 
	{
		for (Node<T>* current = _get_element(start_pos);
			current != nullptr;
			current = current->next, start_pos++)
			if (current->data == value)
				return start_pos;
		return ~0; // unsigned_max
	}

	// Поиск всех элементов со значением value
	// Вернёт список позиций найденных элементов
	vector<unsigned> find_all(T value) 
	{
		vector<unsigned> founds = {};
		unsigned i = 0;
		do
		{
			i = find(value, i);
			if (i != ~0)
				founds.push_back(i);
			else
				break;
		} 
		while (i++ < _nodesСount);
		return founds;
	}

	// Изменяет значение всех найденных вхождения old_value на new_value
	// Вернёт количество замен
	// NotImplemented
	unsigned update_all(T old_value, T new_value) 
	{
		return 0;
	}

	// Обмен местами элементов first и second
	// NotImplemented
	void swap(unsigned first_pos, unsigned second_pos) 
	{

	}

	// Вычисляет длину списка (или возвращает кэшированную)
	// NotImplemented
	unsigned size() 
	{
		return _nodesСount;
	}

	//Оператор [] позволяет по индексу получить ссылку на элемент списка
	T& operator[](unsigned index)
	{
		Node<T>* element = _get_element(index);
		if (element == nullptr)
			throw out_of_range("Ошибка, некорректно задан индекс!");
		return element->data;
	}

	// Выводит список на экран
	void print() 
	{
		cout << endl;
		Node<T>* print_LL = _head;
		while (print_LL != nullptr)
		{
			cout << print_LL->data << " "; // вывод значения элемента 
			print_LL = print_LL->next; // переход к следующему узлу
		} 	
	}

	// Удаляет все элементы из [start; stop]
	// NotImplemented
	void erase(unsigned start, unsigned stop)
	{

	}

	// Удаляет все элементы начиная со start
	void erase(unsigned start)
	{
		erase(start, _nodesСount - 1);
	}

	//Очистить весь список
	void clear()
	{
		erase(0);
	}

	// Очистка памяти, удаление списка
	// NotImplemented
	~LinkedList() 
	{

	}
};
void test();

int main()
{
	setlocale(LC_ALL, "Russian");
	test();
}

void test()
{
	LinkedList<int> list = LinkedList<int>();

	for (int i = 0; i < 10; i++)
		list.push_back(i);
	list.print();

	list.insert(9, 0);
	list.insert(7, 1);
	list.print();

	list.push_front(-1);
	list.push_front(-1);
	list.push_front(-1);
	list.print();

	cout << endl << list[list.size() - 1] << endl;
	list[list.size() - 1] = 0;
	cout << list[list.size() - 1];
	list.print();

	cout << "\nКоличество элементов: " << list.size();
	cout << endl << list.find(8) << endl;
	for (auto i : list.find_all(-1))
	{
		cout << i << " ";
	}
}