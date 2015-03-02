#ifndef LIST_H
#define LIST_H
class List
{
public:
	List();
	List(const List &rhs);
	List & operator =(const List &rhs);
	bool operator ==(const List &rhs);
	void insert(int item);
	void remove();
	void advance();
	void backup();
	void setFront();
	void setBack();
	void print();
	void printCurrent();
private:
	struct ListNode
	{
		int value;
		ListNode *next;
		ListNode *previous;
	};
	ListNode *head;
	ListNode *tail;
	ListNode *cursor;
};
#endif