#include <iostream>
#include <vector>


// Создание шаблонного связного списка

//
template <typename Type>
class LinkedList;


int main() {
	setlocale(LC_ALL, "ru");

	int arr[10];
	std::vector<int> vec(10);
	LinkedList<int> list;
	arr[5] = 34;
	vec[5] = 23;
	list[5] = 12;






	return 0;
}

template <typename Type>
class LinkedList {
public:
	LinkedList();
	LinkedList(int n); // лист с уже созданными N элементами
	LinkedList(const LinkedList &other);// конструктор копирования
	LinkedList(LinkedList&& other); // (конструктор переноса) можно не делать, но для оптимизации скорости работы программы полезно
	// тут не будет реализации конструктора от списка инициализации, внесём позже

	~LinkedList();

	LinkedList& operator = (const LinkedList& other); // присваивание копированием
	LinkedList& operator = (LinkedList&& other); // присваивание переносом

	Type & operator[](int i);
	const Type& operator[](int i)const;

	Type& at(int i);
	const Type& at(int i)const;

	void push_back(const Type& obj); // вставить элемент в конец 
	void push_front(const Type& obj); // вставить элемент в начало

	void pop_back(); // уничтожить данные в конце списка
	void pop_front();// уничтожить данные в начале списка

	//emplace/inesrt - методы добавления новых данных в произвольное место коллекции
	//erise - метод для удаления данных в произвольной точке коллекции

	int size()const;

	//методы для прохода по коллекции умными указателями мы пока сознательно опустим

private:
	class Node {
	public:
		Node()
			:Node(Type()) // при делигации мы вызываем конструктор по умолчанию хранимого типа данных. Данный синтаксис корректно отработает даже если прямой вызов такого метода 
		{}                // (например конструктора встроенных типов) недоступен.

		Node(const Type& data, Node*place=nullptr)
			:data_(data),
			next_(place)
		{}

		Type& Data() {
			return data_;
		}

		const Type& Data() const{
			return data_;
		}

		Node*Next() const{ // метод для предоставления информации о местонахождении следующей точки в списке
			return next_
		}

		void Next(Node* next) { // устанавливаем новое значение для следующей точки 
			next_ = next;
		}

	private:
		Type data_;
		Node* next_;

	};

	Node* start_;
	Node* end_;
	int size_;
	

};