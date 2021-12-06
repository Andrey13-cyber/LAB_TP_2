#pragma once
#include<iostream>

using namespace std;


template <class T>
class Keeper
{
private:
	int mass_lenght;
	T* object;

public:
	Keeper() : mass_lenght(0), object(nullptr) {
	};

	~Keeper() {
		delete[] object;
	}

	Keeper(const Keeper<T>& keeper);

	void pushback(const T& obj);
	void popindex(int index);
	void cleanMass();
	void push(const T& obj, int index);
	void sortAlphabet();
	int getLenght() {
		return mass_lenght;
	}

	T& operator[](int);

};



template <class T>
Keeper<T>::Keeper(const Keeper<T>& keeper) {
	object = new T[keeper.mass_lenght];
	mass_lenght = keeper.mass_lenght;
	for (int i = 0; i < keeper.mass_lenght; i++)
		object[i] = keeper.object[i];
}

template <class T>
void Keeper<T>::cleanMass() {
	delete[] object;
	object = nullptr;
	mass_lenght = 0;
}

template< class T>
T& Keeper<T>::operator[](int index) {
	if (index >= 0 && index < mass_lenght)
		return object[index];
}


template <class T>
void Keeper<T>::pushback(const T& obj) {

	T* temp = object;
	mass_lenght++;
	object = new T[mass_lenght];
	for (int i = 0; i < mass_lenght - 1; i++)
		object[i] = temp[i];
	object[mass_lenght - 1] = obj;

}

template <class T>
void Keeper<T>::push(const T& obj, int index) {

	T* temp = object;
	int k = 0;
	mass_lenght++;
	object = new T[mass_lenght];
	for (int i = 0; i < mass_lenght; i++)
		if (i != index)
			object[i] = temp[k++];
		else
			object[i] = obj;
}

template <class T>
void Keeper<T>::popindex(int index) {
	T* temp = new T[mass_lenght - 1];
	int j = 0;
	for (int i = 0; i < mass_lenght; i++)
		if (i != index)
			temp[j++] = object[i];
	mass_lenght--;
	object = temp;
}

template <class T>
void Keeper<T>::sortAlphabet() {
	for (int i = 1; i < mass_lenght; i++)
		for (int j = 0; j < mass_lenght - i; j++)
			if (object[j] > object[j + 1])
				swap(object[j], object[j + 1]);
}
