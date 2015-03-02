#ifndef BAG_H
#define BAG_H
class Bag
{
public:
	Bag();

	Bag(const Bag &);
	~Bag();
	Bag& operator=(const Bag &);

	void add(int element);
	void remove(int element);

	int occurrences(int element) const;
	bool isEmpty() const;
	int size() const;
	void print()const;

	static const int INCREMENT = 2;
private:
	int *data; //pointer to bag array
	int capacity; //size of the array
	int count; //number of elements currently in array
};
#endif