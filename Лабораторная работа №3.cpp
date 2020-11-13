#include <iostream>
#include <locale.h>

class MaterialObject
{
public:
	double mass; // В граммах
	double volume; // В кубических сантиметрах

	MaterialObject()
	{
		mass = 0;
		volume = 0;
		printf("Создан объект MaterialObject, mass = %f, volume = %f\n", mass, volume);
	}

	MaterialObject(double mass, double volume)
	{
		this->mass = mass;
		this->volume = volume;
		printf("Создан объект MaterialObject, mass = %f, volume = %f\n", mass, volume);
	}

	MaterialObject(const MaterialObject& object)
	{
		mass = object.mass;
		volume = object.volume;
		printf("Скопирован объект MaterialObject, mass = %f, volume = %f\n", mass, volume);
	}

	virtual void message()
	{
		printf("Этот объект принадлежит классу MaterialObject\n");
	}

	virtual ~MaterialObject()
	{
		printf("Удаление объекта MaterialObject, mass = %f, volume = %f\n", mass, volume);
	}
};

class Food :public MaterialObject
{
public:
	Food()
	{
		printf("Создан объект Food, mass = %f, volume = %f\n", mass, volume);
	}
	
	Food(double mass, double volume)
		:MaterialObject(mass, volume)
	{
		printf("Создан объект Food, mass = %f, volume = %f\n", mass, volume);
	}

	Food(const Food& object)
		:MaterialObject(object)
	{
		printf("Скопирован объект Food, mass = %f, volume = %f\n", mass, volume);
	}

	void eatFood(int choice)
	{
		printf("Съели ");
		std::string buffer;
		switch (choice % 5)
		{
			case 0: buffer = "яблоко"; break;
			case 1: buffer = "грушу"; break;
			case 2: buffer = "банан"; break;
			case 3: buffer = "апельсин"; break;
			case 4: buffer = "виноград"; break;
			default: buffer = "лимон"; break;
		}
		std::cout << buffer << std::endl;
	}

	virtual void message()
	{
		printf("Этот объект принадлежит классу Food\n");
	}

	virtual ~Food()
	{
		printf("Удалён объект Food, mass = %f, volume = %f\n", mass, volume);
	}
};

class Clothes :public MaterialObject
{
public:
	Clothes()
	{
		printf("Создан объект Clothes, mass = %f, volume = %f\n", mass, volume);
	}

	Clothes(double mass, double volume)
		:MaterialObject(mass, volume)
	{
		printf("Создан объект Clothes, mass = %f, volume = %f\n", mass, volume);
	}

	Clothes(const Clothes& object)
		:MaterialObject(object)
	{
		printf("Скопирован объект Clothes, mass = %f, volume = %f\n", mass, volume);
	}

	void putOnSomeClothes(int choice)
	{
		printf("Надели ");
		std::string buffer;
		switch (choice % 5)
		{
		case 0: buffer = "свитер"; break;
		case 1: buffer = "футболку"; break;
		case 2: buffer = "джинсы"; break;
		case 3: buffer = "носки"; break;
		case 4: buffer = "куртку"; break;
		default: buffer = "шапку"; break;
		}
		std::cout << buffer << std::endl;
	}

	virtual void message()
	{
		printf("Этот объект принадлежит классу Clothes\n");
	}

	virtual ~Clothes()
	{
		printf("Удалён объект Clothes, mass = %f, volume = %f\n", mass, volume);
	}
};

class Book :public MaterialObject
{
public:
	Book()
	{
		printf("Создан объект Book, mass = %f, volume = %f\n", mass, volume);
	}

	Book(double mass, double volume)
		:MaterialObject(mass, volume)
	{
		printf("Создан объект Book, mass = %f, volume = %f\n", mass, volume);
	}

	Book(const Book& object)
		:MaterialObject(object)
	{
		printf("Скопирован объект Book, mass = %f, volume = %f\n", mass, volume);
	}

	void readBook(int choice)
	{
		printf("Прочитали книгу ");
		std::string buffer;
		switch (choice % 5)
		{
		case 0: buffer = "Пушкина"; break;
		case 1: buffer = "Толстого"; break;
		case 2: buffer = "Островского"; break;
		case 3: buffer = "Гоголя"; break;
		case 4: buffer = "Достоевского"; break;
		default: buffer = "Грибоедова"; break;
		}
		std::cout << buffer << std::endl;
	}

	virtual void message()
	{
		printf("Этот объект принадлежит классу Book\n");
	}

	virtual ~Book()
	{
		printf("Удалён объект Book, mass = %f, volume = %f\n", mass, volume);
	}
};

class Storage
{
private:
	struct Node
	{
		MaterialObject object;
		Node* previous = NULL;
		Node* next = NULL;
	};

	int size;
	Node* first;
	Node* last;
	Node* current;
public:
	Storage()
	{
		size = 0;
		first = NULL;
		last = NULL;
		current = NULL;
		printf("Создан объект Storage, size = 0\n");
	}

	void add(MaterialObject& object) // Добавляет объект в хранилище в конец списка
	{
		Node* temp = new Node();
		temp->object = object;
		size++;

		if (first == NULL)
		{
			first = temp;
			last = temp;
			current = temp;
		}
		else
		{
			last->next = temp;
			temp->previous = last;
			last = temp;
		}
	}

	void del() // Удаляет элемент, на который указывает текущий указатель
	{
		if (current != NULL)
		{
			// Переназначение указателей соседних элементов 
			if(current->previous != NULL)
				current->previous->next = current->next;
			if(current->next != NULL)
				current->next->previous = current->previous;

			// Перевод current на следующий или предыдущий элемент
			Node* oldCurrent = current;

			if (current->next != NULL)
				current = current->next;
			else if (current->previous != NULL)
				current = current->previous;
			else
				current = NULL;

			// Смена указателей first и last, если current был им равен
			if (oldCurrent == first)
				first = current;
			if (oldCurrent == last)
				last = current;

			// Удаление элемента из списка
			size--;
			delete oldCurrent;
		}
	}

	void previous() // Возвращает указатель current на предыдущий элемент в списке, если предыдущий элемент существует
	{
		if (current != NULL)
			if (current->previous != NULL)
				current = current->previous;
	}

	void next() // Возвращает указатель current на следующий элемент в списке, если следующий элемент существует
	{
		if (current != NULL)
			if (current->next != NULL)
				current = current->next;
	}

	bool check(MaterialObject& object) // Проверяет наличие объекта с тем же указателем в хранилище
	{
		Node* buffer = first;
		for (int i = 0; i < size; i++, buffer = buffer->next)
			if (&buffer->object == &object)
				return true;
		return false;
	}
	
	int getSize()
	{
		return size;
	}

	MaterialObject& getFirst() // Возвращает ссылку на первый объект в списке
	{
		return first->object;
	}

	MaterialObject& getLast() // Возвращает ссылку на последний объект в списке
	{
		return last->object;
	}

	MaterialObject& getCurrent() // Возвращает ссылку на текущий объект
	{
		return current->object;
	}

	void setFirst() // Устанавливает текущий указатель на начало списка
	{
		current = first;
	}

	void setLast() // Устанавливает текущий указатель в конец списка
	{
		current = last;
	}

	bool eol() // End Of List
	{
		if (current->next == NULL)
			return true;
		else
			return false;
	}

	virtual ~Storage()
	{
		current = first;
		for (int i = 0; i < size; i++)
		{
			Node* buffer = current->next;
			delete current;
			current = buffer;
		}
		printf("Удалён объект Storage, size = %i\n", size);
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Storage* box = new Storage();
	int count = 10;
	while (count < 10000)
	{
		count *= 10;
		for (int i = 0; i < count; i++)
		{
			int key = rand();
			
			if (box->getSize() == 0 || key % 5 <= 1) // Добавить объект
			{
				if (key % 3 == 0)
					box->add(*(new Food(key % 1000, key % 100)));
				else if (key % 3 == 1)
					box->add(*(new Clothes(key % 500, key % 200)));
				else if (key % 3 == 2)
					box->add(*(new Book(key % 500, key % 100)));
			}
			else if (key % 5 == 2) // Удалить объект
			{
				for (int j = 0; j < (key % box->getSize()); j++)
					;
				int j = 0;
				while (j != key % box->getSize())
				{

				}
			}
		}
	}
}