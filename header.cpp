#include "header.h"
#include"iostream"
#include<cassert>

using namespace std;

List::List()
{
	head = NULL;
	tail = NULL;
	cursor = NULL;
}
List::List(const List &rhs)
{
	head = NULL;
	tail = NULL;
	cursor = NULL;
	int count = 0;

	ListNode *n;

	for (n = rhs.head; n != NULL; n = n->next)
		insert(n->value);
	for (n = rhs.head; n != rhs.cursor; n = n->next)
		count++;
	setFront();
	for (int i = 0; i < count; i++)
		cursor = cursor->next;
}
List &List:: operator =(const List &rhs)
{
	ListNode *p;
	int count = 0;

	if (&rhs != this)
	{
		setFront();

		while (cursor)
			remove();

		for (p = rhs.head; p != NULL; p = p->next)
			insert(p->value);

		for (p = rhs.head; p != rhs.cursor; p = p->next)
			count++;

		setFront();
		for (int i = 0; i < count; i++)
			cursor = cursor->next;
	}
	return *this;
}
bool List::operator ==(const List &rhs)
{
	bool identical = true;

	int count = 0, count2 = 0;
	
	for (ListNode *n = head; n != NULL; n = n->next)
		count++;
	for (ListNode *n = rhs.head; n != NULL; n = n->next)
		count2++;

	if (count != count2)
		identical = false;

	else
	{
		ListNode *n = head, *p = rhs.head;

		while (n && identical != false)
		{
			if (p->value != n->value)
				identical = false;
			n = n->next;
			p = p->next;
		}
	}
	return identical;
}
void List::insert(int item)
{
	ListNode *newNode = new ListNode;

	newNode->value = item;

	if (!head)
	{
		head = newNode;
		tail = newNode;
		head->previous = NULL;
		tail->next = NULL;
	}
	else
	{
		if (cursor == head)
		{
			head = newNode;
			newNode->next = cursor;
			cursor->previous = newNode;
			newNode->previous = NULL;
		}
		else
		{
			if (cursor == NULL)
			{
				tail->next = newNode;
				newNode->previous = tail;
				newNode->next = NULL;
				tail = newNode;
			}
			else
			{
				ListNode *p = cursor->previous;

				p->next = newNode;
				newNode->previous = p;
				newNode->next = cursor;
				cursor->previous = newNode;
			}
		}
	}
}
void List::remove()
{
	assert(cursor != NULL);

	if (cursor == head)
	{
		if (head->next == NULL)
		{
			delete head;
			cursor = NULL;
			head = NULL;
			tail == NULL;
		}
		else
		{
			cursor = head->next;
			delete head;
			head = cursor;
			cursor->previous = NULL;
		}
	}
	else if (cursor == tail)
	{
		tail = cursor->previous;
		delete cursor;
		tail->next = NULL;
		cursor = NULL;
	}
	else
	{
		ListNode *n = cursor->previous;
		ListNode *p = cursor->next;

		delete cursor;
		cursor = p;
		p->previous = n;
		n->next = p;
	}
}
void List::setFront()
{
	cursor = head;
}
void List::setBack()
{
	cursor = tail;
}
void List::advance()
{
	if (cursor != NULL)
		cursor = cursor->next;
}
void List::backup()
{
	if (cursor != NULL)
		cursor = cursor->previous;
}
void List::print()
{
	ListNode *iter;

	for (iter = head; iter != NULL; iter = iter->next)
		cout << iter->value << ",";
	cout << endl;
	
}
void List::printCurrent()
{
	cout << "cursor is on " << cursor->value << endl;
}