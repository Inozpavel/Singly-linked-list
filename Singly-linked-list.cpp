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


template <typename T>
class LinkedList 
{
private:
	Node<T>* head;
	Node<T>* tail;
	unsigned nodes_count;

	// Удаляет элемент, сохраняя целосность списка
	// previous = nullptr для удаления головного объекта
	// NotImplemented
	void remove_node(Node<T>* node, Node<T>* previous)
	{

	}

public:
	LinkedList() : head(nullptr), nodes_count(0) 
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
	// В случае успеха вернёт позицию элемента
	// NotImplemented
	unsigned find(T value, unsigned start_pos = 0) 
	{
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

	// Вычисляет длинну списка (или возвращает кешированную)
	// NotImplemented
	unsigned size() 
	{
		return 0;
	}

	// Выводит список на экран
	// NotImplemented
	void print() 
	{

	}

	// Удаляет все элементы
	// NotImplemented
	void erase() 
	{

	}

	// Очистка памяти, удаление списка
	// NotImplemented
	~LinkedList() 
	{

	}
};

int main() 
{
	cout << "Тесты не реализованы!\n";
}