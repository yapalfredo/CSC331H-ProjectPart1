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
    //constructor
    list();
    //destructor
    ~list();
    //copy constructor
    //list (const list &)...

    //operator overloading
    //operator=

    void insertFront(T);     //insert at the beginning.
    void insertAfter(T,T);   //insert after..
    void insertBefore(T,T);  //insert before..
    void insertEnd(T);       //insert at the end.
    void deleteItem(T);
    bool searchItem(T);
    void printListF();
    void printListB();
};

#include "dll.tpp"