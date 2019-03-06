#include <iostream>

#ifndef DLL_H
#define DLL_H

template <class T>
struct node
{
	T data;
	node<T> *prev;
	node<T> *next;
};

template <class T>
class list
{
private:
	int length;
	node<T> *head;
	void copyOther(const list<T>&);
	void clear(); //used for invoking destructor
	void clear(node<T>*&); //used to free up and delete a node
public:
	// constructor
	list();
	// copy constructor
	list(const list<T>&);
	// destructor
	~list();
	// operator overloading
	// operator=
	list<T>& operator=(const list<T>&);

	class Iterator;
	Iterator begin() const { return Iterator(head); }
	Iterator end() const {
		node<T> *temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		return Iterator(temp);
	}

	void insertFront(T);     // insert at the beginning.
	void insertAfter(T, T);   // insert after..
	void insertEnd(T);       // insert at the end.

	void deleteNode(T);   //used for deleting node

	void printListF();		//print in reverse order
	void printListB();    //print in LIFO order

	void increaseLength();
	void decreaseLength();
	int getLength();

	bool searchItem(T);
};
#include "dll.cpp"
#endif
