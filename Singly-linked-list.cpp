#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
	Node<T>* _tail;
	unsigned _nodes_count;

	// Удаляет элемент, сохраняя целосность списка
	// previous = nullptr для удаления головного объекта
	void remove_node(Node<T>* node, Node<T>* previous)
	{
		if (previous != nullptr)
			previous->next = node->next;
		delete node;
	}

public:
	LinkedList() : _head(nullptr), _nodes_count(0) 
	{
	}

	// Добавление элемента (после pos)
	// NotImplemented
	void insert(T element, unsigned pos)
	{

	}

	// Добавление элемента (до pos)
	// NotImplemented
	void insert_before(T element, unsigned pos) 
	{

	}

	// Добавление элемента в конец
	void push_back(T element) 
	{
		insert(element, _nodes_count);
	}

	// Добавление элемента в начало
	void push_front(T element) 
	{
		insert_before(element, 0);
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
		for (Node<T>* current = this[start_pos];
			current != nullptr;
			current = current->next, start_pos++)
			if (current->data == value)
				return start_pos;
		return ~0; // unsigned_max
	}

	// Поиск всех элементов со значением value
	// Вернёт список позиций найденных элементов
	// NotImplemented
	vector<unsigned> find_all(T value) 
	{
		return {};
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
		return _nodes_count;
	}

	void operator[](unsigned index)
	{
		return;
	}

	// Выводит список на экран
	void print() 
	{
		Node<T>* print_LL = _head;
		while (print_LL != nullptr)
		{
			cout << print_LL->data; // вывод значения элемента 
			print_LL = print_LL->next; // переход к следующему узлу
		} 	
	}

	// Удаляет все элементы из [start; stop]
	// NotImplemented
	void erase(unsigned start, unsigned stop)
	{

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

int main() 
{
	setlocale(LC_ALL, "Russian");
	LinkedList<int> list = LinkedList<int>();
	list.print();
	cout << "Тесты не реализованы!\n";
}