#include <iostream>

class MaterialObject
{
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

	MaterialObject(MaterialObject& object)
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

int main()
{
	
}



