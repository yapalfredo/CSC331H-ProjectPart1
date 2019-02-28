#include <iostream>

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
  public:
    // constructor
    list();
    // copy constructor
    list(const list&);
    // destructor
    ~list();

    // operator overloading
    // operator=

    void put(T);     // insert at the beginning.
    void insertAfter(T,T);   // insert after..
    void insertBefore(T,T);  // insert before..
    void insertEnd(T);       // insert at the end.
    
    void pull(T);   //used for deleting node
    
    void printListF();
    void printListB();    //print in LIFO order

    void increaseLength();
    void decreaseLength();
    int getLength();

    bool searchItem(T);
};

#include "dll.tpp"