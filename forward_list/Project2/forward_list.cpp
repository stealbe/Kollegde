#include <iostream>
using namespace std;


template <class T>
struct Element
{
	// Данные
	T data;
	// Адрес следующего элемента списка
	Element* Next;
};

// Односвязный список
template<class T>
class List
{
	// Адрес головного элемента списка
	Element<T>* Head;
	// Адрес головного элемента списка
	Element<T>* Tail;
	// Количество элементов списка
	int Count;

public:
	// Конструктор
	List();
	// Деструктор
	~List();

	// Добавление элемента в список
	// (Новый элемент становится последним)
	void Add(T data);

	void Paste(T data, int id);

	// Удаление элемента списка
	// (Удаляется головной элемент)
	void Del();

	void Del(int id);
	// Удаление всего списка
	void DelAll();

	// Распечатка содержимого списка
	// (Распечатка начинается с головного элемента)
	void Print();

	// Получение количества элементов, находящихся в списке
	int GetCount();
	int GetId(T data);
	T* GetItem(int id);
};

template <class T>
List<T>::List()
{
	// Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}

template <class T>
List<T>::~List()
{
	// Вызов функции удаления
	DelAll();
}
template <class T>
int List<T>::GetCount()
{
	// Возвращаем количество элементов
	return Count;
}

template<class T>
int List<T>::GetId(T data)
{
	Element<T>* temp = new Element<T>;
	for (size_t i = 0; i < this->Count; i++)
	{
		if (temp->data == data) return i;
	}
	return -1;
}

template<class T>
T* List<T>::GetItem(int id)
{
	Element<T>* temp = new Element<T>;
	for (size_t i = 0; i < id; i++)
	{
		temp->Next = temp->Next->Next;
	}
	return temp->Next;
}

template <class T>
void List<T>::Add(T data)
{
	// создание нового элемента
	Element<T>* temp = new Element<T>;

	// заполнение данными
	temp->data = data;
	// следующий элемент отсутствует
	temp->Next = NULL;
	// новый элемент становится последним элементом списка
	// если он не первый добавленный
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// новый элемент становится единственным
	// если он первый добавленный
	else {
		Head = Tail = temp;
	}
	this->Count++;
}

template<class T>
void List<T>::Paste(T data, int id)
{
	Element<T>* temp = new Element<T>;
	temp->data = data;
	if (Head != NULL) {
		if (Tail != GetItem(id - 1)) temp->Next = GetItem(id + 1);
		else {
			temp->Next = NULL;
			Tail = temp;
		}
		GetItem(id - 1)->Next = temp;
	}
	else {
		Head = Tail = temp;
	}
	this->Count++;
}

template <class T>
void List<T>::Del()
{
	// запоминаем адрес головного элемента
	Element<T>* temp = Head;
	// перебрасываем голову на следующий элемент
	Head = Head->Next;
	// удаляем бывший головной элемент
	delete temp;
}

template<class T>
void List<T>::Del(int id)
{
	if (id < 0 || id >= this->Count) throw "err";
	Element<T>* temp = GetItem(id);
	if (this->Count == 1) this->Head = this->Tail = nullptr;
	else if (id == 0) this->Head = temp->Next;
	else if (id == this->Count - 1)
	{
		Element<T>* prev = GetItem(id - 1);
		prev->Next = nullptr;
		this->Tail = prev;
	}
	else GetItem(id - 1)->Next = temp->Next;
	delete temp;
	this->Count--;
}

template <class T>
void List<T>::DelAll()
{
	// Пока еще есть элементы
	while (Head != 0)
		// Удаляем элементы по одному
		Del();
	this->Count = 0;
}

template <class T>
void List<T>::Print()
{
	// запоминаем адрес головного элемента
	Element<T>* temp = Head;
	// Пока еще есть элементы
	while (temp != 0)
	{
		// Выводим данные
		cout << temp->data << " ";
		// Переходим на следующий элемент
		temp = temp->Next;
	}
	cout << "\n\n";
}

// Тестовый пример
int main()
{
	// Создаем объект класса List
	List<char> lst;

	// Тестовая строка
	char s[] = "Hello, World !!!\n";
	// Выводим строку
	cout << s << "\n\n";
	// Определяем длину строки
	int len = strlen(s);
	// Загоняем строку в список
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	// Распечатываем содержимое списка
	lst.Print();
	// Удаляем три элемента списка
	lst.Del();
	lst.Del();
	lst.Del();
	//Распечатываем содержимое списка
	lst.Print();
}

