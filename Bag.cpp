#include "Bag.h"
#include<iostream>
using namespace std;

Bag::Bag()
{
	capacity = INCREMENT;
	data = new int[capacity];
	count = 0;
}
Bag::Bag(const Bag & rhs)
{
	count = rhs.count;
	capacity = rhs.capacity;
	data = new int[capacity];

	for (int i = 0; i < count; i++)
		data[i] = rhs.data[i];
}
Bag& Bag::operator=(const Bag &rhs)
{
	if (&rhs != this)
	{
		if (data)
			delete [] data;

		count = rhs.count;
		capacity = rhs.capacity;
		data = new int[capacity];

			for (int i = 0; i < count; i++)
				data[i] = rhs.data[i];
	}
	return *this;
}
void Bag::print()const
{
	for (int i = 0; i < count; i++)
		cout << data[i] << ",";
	cout << endl;
}
void Bag::add(int element)
{
	int *temp;

	if (count == capacity)
	{
		temp = new int[capacity+INCREMENT];

		for (int i = 0; i < capacity; i++)
			temp[i] = data[i];
		delete [] data;
		data = temp;

		data[capacity] = element;
		capacity = capacity + INCREMENT;
	}
	else
		data[count] = element;
	
	count++;
}
void Bag::remove(int element)
{
	int found = -1;
	for (int i = 0; i < count && found == -1; i++)
		if (data[i] == element)
			found = i;

	if (found != -1)
		for (int i = found; i < count - 1; i++)
			data[i] = data[i + 1];
	count--;
}
bool Bag::isEmpty()const
{
	return count == 0;
}
int Bag::occurrences(int element)const
{
	int count = 0;
	for (int i = 0; i < count; i++)
		if (element == data[i])
			count++;
	return count;
}
int Bag::size()const
{
	return count;
}
Bag::~Bag()
{
	delete[] data;
	data = NULL;
}