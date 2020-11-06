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

	virtual void message()
	{
		printf("Этот объект принадлежит классу Book\n");
	}

	virtual ~Book()
	{
		printf("Удалён объект Book, mass = %f, volume = %f\n", mass, volume);
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

}