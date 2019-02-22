
template <class T>
list<T>::list()
{
  head = NULL;
  length = 0;
}

template <class T>
list<T>::~list()
{

}

template <class T>
void list<T>::insertFront(T item)
{
  node<T> *temp = new node<T>;
  temp -> data = item;

  if (head == NULL)
  {
    temp -> prev = NULL;
    temp -> next = NULL;
    head = temp;
    temp = NULL;
  }
  else
  {
    temp -> prev = NULL;
    temp -> next = head;
    head = temp;
    temp = NULL;
  }
  delete temp;
}

template <class T>
void list<T>::insertAfter(T sItem, T item)
{
  
  if(searchItem(sItem))
  {
    std::cout << "Found! \n";
  }
  else
  {
    std::cout << "Not found! \n";
  }

}

template <class T>
void list<T>::printList()
{
  node<T> *temp = head;

  T * array = new T;
  int l = 0;

  while (temp!=NULL)
  {
    *(array+l) = temp->data;
    temp = temp->next;
    l++;
  }

  for(int x = 0; x<l; l--)
  {
    std::cout << *(array+l-1) << " ";
  }

  temp = NULL;
  array = NULL;
  delete temp;
  delete array;
}

template <class T>
bool list<T>::searchItem(T item)
{
  bool result =false;
  node<T> *temp = head;
  while(temp!=NULL)
  {
    if (temp->data == item)
    {
      result = true;
    }
    temp = temp->next;
  }
  return result;

  temp = NULL;
  delete temp;
}