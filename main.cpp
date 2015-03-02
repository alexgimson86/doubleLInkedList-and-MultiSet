#include"header.h"
#include "Bag.h"

#include<iostream>
using namespace std;

int main()
{
	Bag bag;
	
	for (int i = 0; i < 10; i++)
		bag.add(i);
	bag.print();
	bag.remove(6);
	bag.print();

	Bag b2;
	b2 = bag;
	b2.print();
	b2.remove(9);
	b2.print();
	b2.remove(0);
	b2.print();

	List list;
	List list2 = list;
	
	for (int i = 0; i < 10; i++)
		list.insert(i);
	for (int i = 0; i < 10; i++)
		list2.insert(i);
	list2.insert(11);
	list2 = list;
	if (list == list2)
		cout << "theyre same right now" << endl;
	list2.insert(11);
	if (!(list == list2))
		cout << "theyre  not same" << endl;

	
	system("pause");
	return 0;
}