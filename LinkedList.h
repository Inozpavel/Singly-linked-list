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
	Linked List[0] = head
	Linked List[1] = head.next
	Linked List[2] = head.next.next
	*/
private:
	//Узел списка, содержит данные и указатель на следующий элемент
	struct Node
	{
		T data;
		Node* next;
		Node(T data, Node* next = nullptr) : data(data), next(next)
		{
		}
	};
	Node* _head;
	unsigned _nodesCount;

	// Удаляет элемент, сохраняя целосность списка
	// previous = nullptr для удаления головного объекта
	void _remove_node(Node* node, Node* previous = nullptr)
	{
		if (node == nullptr) return;
		if (previous != nullptr)
			previous->next = node->next;
		else
			_head = node->next;
		delete node;
	}
	// Ищет элемент с начала списка по индексу
	// В стучае успеха возвращает указатель на него, иначе nullptr
	Node* _get_element(unsigned index)
	{
		if (index >= _nodesCount)
			return nullptr;
		Node* current = _head;
		unsigned i = 0;
		while (current != nullptr && i < index)
		{
			current = current->next;
			i++;
		}
		return current;
	}
	// Получает предыдущий Node
	// Возвращает указатель на него в случае успеха, иначе nullptr
	Node* _get_previous(Node* node)
	{
		Node* previousElement = nullptr;
		for (Node* startElement = _head;
			startElement != nullptr;
			startElement = startElement->next)
		{
			if (startElement == node)
				return previousElement;
			previousElement = startElement;
		}
		return nullptr;
	}
	// Ищет Node, данные в которой равны value
	// Возвращает указатель на него в случае успеха, иначе nullptr
	Node* _search(T value, Node* startElement = nullptr)
	{
		Node* current = startElement;
		if (startElement == nullptr)
			current = _head;
		for (; current != nullptr; current = current->next)
			if (current->data == value)
				return current;
		return nullptr;
	}

public:
	static unsigned const NOT_FOUND = ~0;
	LinkedList() : _head(nullptr), _nodesCount(0)
	{
	}

#pragma region Adding elements

	// Добавление элемента на указанную позицию
	void insert(unsigned pos, T element)
	{
		if (_nodesCount == 0)
			_head = new Node(element);
		else
		{
			if (pos == 0)
				_head = new Node(element, _head);
			else
			{
				Node* current = _get_element(pos - 1);
				current->next = new Node(element, current->next);
			}
		}
		_nodesCount++;
	}

	// Добавление элемента в конец списка
	void push_back(T element)
	{
		insert(_nodesCount, element);
	}

	// Добавление элемента в начало	списка
	void push_front(T element)
	{
		insert(0, element);
	}

#pragma endregion		 

#pragma region Methods remove

	// Удаление одного (первого) элемента по значению value
	// Вернёт true в случае успешного удаления, иначе false
	bool remove(T value)
	{
		Node* foundElem = _search(value);
		if (foundElem == nullptr)
			return false;
		_remove_node(foundElem, _get_previous(foundElem));
		_nodesCount--;
		return true;
	}

	// Удаление элемента на позиции pos
	// Вернёт true в случае успешного удаления, иначе false
	bool remove_at(unsigned pos)
	{
		if (pos >= _nodesCount)
			return false;
		if (pos == 0)
			_remove_node(_head);
		else
		{
			Node* previous = _get_element(pos - 1);
			if (previous == nullptr)
				return false;
			_remove_node(previous->next, previous);
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

#pragma endregion

#pragma region Methods find

	// Поиск одного элемента по значению
	// В случае успеха вернёт позицию первого элемента, иначе константу NOT_FOUND
	unsigned find(T value, unsigned start_pos = 0)
	{
		for (Node* current = _get_element(start_pos);
			current != nullptr;
			current = current->next, start_pos++)
			if (current->data == value)
				return start_pos;
		return NOT_FOUND;
	}

	// Поиск всех элементов со значением value
	// Вернёт список (vector<unsigned>) всех позиций найденных элементов
	vector<unsigned> find_all(T value)
	{
		vector<unsigned> founds = {};
		unsigned i = 0;
		do
		{
			i = find(value, i);
			if (i != NOT_FOUND)
				founds.push_back(i);
			else
				break;
		} while (i++ < _nodesCount);
		return founds;
	}

#pragma endregion

#pragma region Methods update


	// Изменяет значение первого найденного элемента old_value на new_value 
	bool update(T old_value, T new_value)
	{
		Node* current = _search(old_value);
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
		Node* current = nullptr;
		do
		{
			current = _search(old_value, current);
			if (current == nullptr)
				return i;
			current->data = new_value;
		} while (i++ < _nodesCount);
		return i;
	}

#pragma endregion

#pragma region Useful methods

	// Обмен местами элементов двух элементов
	void swap(unsigned firstIndex, unsigned secondIndex)
	{
		if (_nodesCount == 0)
			throw out_of_range("Ошибка! Список пуст!");
		if (firstIndex >= _nodesCount || secondIndex >= _nodesCount)
			throw out_of_range("Ошибка! Некорректный индекс!");
		T data = _get_element(firstIndex)->data;
		_get_element(firstIndex)->data = _get_element(secondIndex)->data;
		_get_element(secondIndex)->data = data;
	}

	// Возвращает количество элементов в списке
	unsigned size()
	{
		return _nodesCount;
	}

	// Оператор [] позволяет по индексу получить ссылку на элемент списка
	T& operator[](unsigned index)
	{
		Node* element = _get_element(index);
		if (element == nullptr)
			throw out_of_range("Ошибка, некорректно задан индекс!");
		return element->data;
	}

	// Выводит список на экран
	void print_all()
	{
		cout << "Список:" << endl;
		Node* current = _head;
		while (current != nullptr)
		{
			cout << current->data << endl; // вывод значения элемента
			current = current->next; // переход к следующему узлу
		}
		if (_nodesCount != 0)
			cout << endl;
	}

#pragma endregion

#pragma region Methods erase clear

	// Удаляет все элементы из диапазона [start..stop]
	// stopIndex индекс включается в диапазон
	void erase(unsigned startIndex, unsigned stopIndex)
	{
		if (_nodesCount == 0)
			return;
		if (stopIndex >= _nodesCount)
			throw out_of_range("Ошибка! Некорректно задан индекс!");
		while (startIndex <= stopIndex)
		{
			remove_at(startIndex);
			stopIndex--;
		}
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
	~LinkedList()
	{
		clear();
	}

#pragma endregion

};

#endif


