#include "dll.h"

template <class T>
list<T>::list()
{
	head = nullptr;
	length = 0;
}

template <class T>
void list<T>::copyOther(const list<T>& other)
{

	for (node<T> *src = other.head; src != nullptr; src = src->next)
	{
		node<T> *newNode = new node<T>;
		newNode->data = src->data;
		newNode->next = head;
		newNode->prev = nullptr;

		if (head != nullptr)
		{
			head->prev = newNode;
		}
		head = newNode;
	}
	length = other.length;

}

template <class T>		// copy constructor
list<T>::list(const list<T>&other)
{
	copyOther(other);
}

template <class T>		// operator assignment
list<T>& list<T>::operator=(const list<T>& other)
{
	if (this != &other)
	{
		clear();
		copyOther(other);
	}
	return *this;
}

template <class T>
void list<T>::clear()
{
	while (this->head != nullptr)
	{
		node<T> *_next = this->head->next;
		delete this->head;
		this->head = _next;
	}
	length = 0;
}

template <class T>
void list<T>::clear(node<T>*& _node)
{
	_node = nullptr;
	delete _node;
}

template <class T>
list<T>::~list()
{
	clear();
}

template <class T>
void list<T>::insertFront(T item)
{
	node<T> *newNode = new node<T>;
	newNode->data = item;
	newNode->next = head;
	newNode->prev = nullptr;

	if (head != nullptr)
	{
		head->prev = newNode;
	}

	head = newNode;

	increaseLength();
}

template <class T>
void list<T>::insertAfter(T sItem, T item)
{
	bool result = false;
	node<T> *temp = head;
	node<T> *newNode = nullptr;

	while (temp != nullptr)
	{
		if (temp->data == sItem)
		{
			result = true;
			newNode = new node<T>;
			break;
		}
		temp = temp->next;
	}

	if (result)
	{
		newNode->data = item;
		newNode->next = temp->next;
		temp->next = newNode;
		newNode->prev = temp;

		if (newNode->next != nullptr)
		{
			newNode->next->prev = newNode;
		}
		increaseLength();
	}
	else
	{
		std::cout << "Not found! \n";
	}

	clear(temp);
}

template <class T>
void list<T>::insertEnd(T item)
{
	node<T> *newNode = new node<T>;
	node<T> *temp = head;
	newNode->data = item;
	newNode->next = newNode->prev = nullptr;

	if (head == nullptr)
	{
		head = newNode;
		return;
	}

	while (temp->next != nullptr)
	{
		temp = temp->next;
	}

	temp->next = newNode;
	newNode->prev = temp;

	increaseLength();

	clear(temp);
}

template <class T>
void list<T>::deleteNode(T item)
{
	if (head == nullptr || item == NULL)
	{
		return;
	}

	if (getLength() >= 1)
	{
		bool result = false;
		node<T> *temp = head;

		while (temp != nullptr)
		{
			if (temp->data == item)
			{
				result = true;
				break;
			}
			temp = temp->next;
		}

		if (result)
		{
			node<T> *temp2 = temp;
			if (head->data == temp->data)
			{
				head = temp->next;
			}
			if (temp->next != nullptr)
			{
				temp->next->prev = temp->prev;
			}
			if (temp->prev != nullptr)
			{
				temp->prev->next = temp->next;
			}


			clear(temp);
			decreaseLength();
		}
		else
		{
			std::cout << "Cannot find the node to be deleted! \n";
		}
	}
}

template <class T>
void list<T>::printListF()
{
	node<T> *temp = head;

	T * array = new T;
	int l = 0;

	while (temp != nullptr)
	{
		*(array + l) = temp->data;
		temp = temp->next;
		l++;
	}

	for (int x = 0; x < l; l--)
	{
		std::cout << *(array + l - 1) << " ";
	}

	clear(temp);
	clear(array);
}

template <class T>
void list<T>::printListB()
{
	for (node<T>* node = head; node != nullptr; node = node->next)
	{
		std::cout << node->data << " ";
	}
}

template <class T>
bool list<T>::searchItem(T item)
{
	bool result = false;
	node<T> *temp = head;
	while (temp != nullptr)
	{
		if (temp->data == item)
		{
			result = true;
		}
		temp = temp->next;
	}
	clear(temp);
	return result;
}

template <class T>
void list<T>::increaseLength()
{
	length++;
}

template <class T>
void list<T>::decreaseLength()
{
	if (length > 0)
	{
		length--;
	}
}

template <class T>
int list<T>::getLength()
{
	return length;
}

template <class T> class list<T>::Iterator
{
	friend class list;
private:
	node<T> *iter;
	Iterator(node<T> *newPtr) : iter(newPtr) {}
public:
	Iterator() : iter(nullptr) {}

	Iterator operator++(int)
	{
		if (iter != nullptr)
		{
			iter = iter->next;
		}
		return iter;
	}

	T& operator*() const
	{
		return iter->next->data;
	}

	bool operator!=(const Iterator& itr) const
	{
		return iter != itr.iter;
	}
};