#ifndef LINKED_LISH_H
#define LINKED_LIST_H

#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::out_of_range;
using std::cout;
using std::endl;

template <typename T>
class LinkedList
{
	/* Структура связного списка:
	head -> node_1 -> ... -> node_n -> nullptr
	head так же node, но самый первый
	node указывающий на nullptr называется хвостом (tail)
	Linked List (связный список) будем называть просто списком или LL
	LL[0] = head
	LL[1] = head.next
	LL[2] = head.next.next
	*/
private:
	//Узел списка, содержит данные и указатель на следующий элемент
	template <typename T>
	struct Node
	{
		T data;
		Node* next;
		Node(T data, Node* next = nullptr) : data(data), next(next)
		{
		}
	};
	Node<T>* _head;
	unsigned _nodesCount;

	// Удаляет элемент, сохраняя целосность списка
	// previous = nullptr для удаления головного объекта
	void remove_node(Node<T>* node, Node<T>* previous = nullptr)
	{
		if (node == nullptr) return;
		if (previous != nullptr)
			previous->next = node->next;
		else
			_head = node->next;
		delete node;
	}
	// Ищет элемент с начаал списка по индексу
	// В стучае успеха возвращает указатель на него, иначе nullptr
	Node<T>* _get_element(unsigned index)
	{
		if (index >= _nodesCount)
			return nullptr;
		Node<T>* current = _head;
		unsigned i = 0;
		while (current != nullptr && i < index)
		{
			current = current->next;
			i++;
		}
		return current;
	}
	// Получает предыдущий Node
	Node<T>* _get_previous(Node<T>* node)
	{
		Node<T>* previous = nullptr;
		for (Node<T>* element = _head;
			element == nullptr;
			element = element->next) {
			if (element == node)
				return previous;
			previous = element;
		}
		return nullptr;
	}
	// Ищет Node, данные в которой равны value
	// Возвращает указатель на него в случае успеха, иначе nullptr
	Node<T>* _search(T value, Node<T>* startElem = nullptr)
	{
		Node<T>* current = startElem;
		if (startElem == nullptr)
			current = _head;
		for (; current != nullptr; current = current->next)
			if (current->data == value)
				return current;
		return nullptr;
	}

public:
	LinkedList() : _head(nullptr), _nodesCount(0)
	{
	}

	// Добавление элемента на указанную позицию
	void insert(unsigned pos, T element)
	{
		if (_nodesCount == 0)
			_head = new Node<T>(element);
		else
		{
			if (pos == 0)
				_head = new Node<T>(element, _head);
			else
			{
				Node<T>* current = _get_element(pos - 1);
				current->next = new Node<T>(element, current->next);
			}
		}
		_nodesCount++;
	}

	// Добавление элемента в конец
	void push_back(T element)
	{
		insert(_nodesCount, element);
	}

	// Добавление элемента в начало
	void push_front(T element)
	{
		insert(0, element);
	}

	// Удаление одного элемента по значению value
	// Вернёт true в случае успеха (нашёл)
	bool remove(T value)
	{
		Node<T>* foundElem = _search(value);
		if (foundElem == nullptr)
			return false;
		remove_node(foundElem, _get_previous(foundElem));
		_nodesCount--;
		return true;
	}

	// Удаление элемента на позиции pos
	bool remove_at(unsigned pos)
	{
		if (pos >= _nodesCount)
			return false;
		if (pos == 0)
			remove_node(_head);
		else
		{
			Node<T>* previous = _get_element(pos - 1);
			if (previous == nullptr)
				return false;
			remove_node(previous->next, previous);
		}
		_nodesCount--;
		return true;
	}

	// Удаление всех элементов со значением value
	// Вернёт количество удалённых элементов
	unsigned remove_all(T value)
	{
		unsigned count = 0;
		while (remove(value))
			count++;
		return count;
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
		} while (i++ < _nodesCount);
		return founds;
	}
	// Изменяет значение первого найденного элемента old_value на new_value 
	bool update(T old_value, T new_value)
	{
		Node<T>* current = _search(old_value);
		if (current == nullptr)
			return false;
		current->data = new_value;
		return true;
	}
	// Изменяет значение всех найденных вхождения old_value на new_value
	// Вернёт количество замен
	unsigned update_all(T old_value, T new_value)
	{
		unsigned i = 0;
		Node<T>* current = nullptr;
		do
		{
			current = _search(old_value, current);
			if (current == nullptr)
				return i;
			current->data = new_value;
		} while (i++ < _nodesCount);
		return i;
	}

	// Обмен местами элементов first и second
	void swap(unsigned first_pos, unsigned second_pos)
	{
		if (_nodesCount == 0)
			throw out_of_range("Ошибка! Список пуст!");
		if (first_pos >= _nodesCount || second_pos >= _nodesCount)
			throw out_of_range("Ошибка! Некорректный индекс!");
		Node<T>* data = _get_element(first_pos)->data;
		_get_element(first_pos)->data = _get_element(second_pos)->data;
		_get_element(second_pos)->data = data;
	}

	// Вычисляет длину списка (или возвращает кэшированную)
	unsigned size()
	{
		return _nodesCount;
	}

	// Оператор [] позволяет по индексу получить ссылку на элемент списка
	T& operator[](unsigned index)
	{
		Node<T>* element = _get_element(index);
		if (element == nullptr)
			throw out_of_range("Ошибка, некорректно задан индекс!");
		return element->data;
	}

	// Выводит список на экран
	void print_all()
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
	bool erase(unsigned start, unsigned stop)
	{
		for (; start < stop; stop--)
		{
			if (!remove_at(start))
				return false;
		}
		return true;
	}

	// Удаляет все элементы начиная со start
	void erase(unsigned start)
	{
		erase(start, _nodesCount);
	}

	// Очищает весь список
	void clear()
	{
		erase(0);
	}

	// Очистка памяти, удаление списка
	// NotImplemented
	~LinkedList()
	{
		clear();
	}
};

#endif


