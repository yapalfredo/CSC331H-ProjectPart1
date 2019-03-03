template <class T>
list<T>::list()
{
  head = NULL;
  length = 0;
}

template <class T>
void list<T>::copyOther(const list<T>& other)
{
  for (node<T> *src = other.head; src!= nullptr; src = src->next)
  {
    node<T> *newNode = new node<T>;
    newNode -> data = src -> data;
    newNode -> next = head;
    head = newNode;
  }
  length = other.length;

}

template <class T>
list<T>::list(const list<T>&other)
{
  copyOther(other);
}

template <class T>
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
  while(this->head!=nullptr)
  {
    node<T> *_next = this->head->next;
    delete this->head;
    this->head = _next;
  }
  length = 0;
}

template <class T>
list<T>::~list()
{
  clear();
}

template <class T>
void list<T>::put(T item)
{
  node<T> *newNode = new node<T>;
  newNode -> data = item;
  newNode -> next = head;
  newNode -> prev = NULL;

  if (head != NULL)
  {
    head -> prev = newNode;
  }

  head = newNode;

  increaseLength();
}

template <class T>
void list<T>::insertAfter(T sItem, T item)
{
  bool result = false;
  node<T> *temp = head;
  node<T> *newNode;

  while(temp!=NULL)
  {
    if (temp->data == sItem)
    {
      result = true;
      newNode = new node<T>;
     break;
    }
    temp = temp->next;
  }

  if(result)
  {
    newNode -> data = item;
    newNode -> next = temp -> next; 
    temp -> next = newNode;
    newNode -> prev = temp;
    
    if (newNode->next != NULL)
    {
      newNode -> next -> prev = newNode;
    }
    increaseLength();
  }
  else
  {
    std::cout << "Not found! \n";
  }

  temp = NULL;
  delete temp;
}

template <class T>
void list<T>::insertEnd(T item)
{
  node<T> *newNode = new node<T>;
  node<T> *temp = head;
  newNode -> data = item;
  newNode -> next = NULL;

  if (head == NULL)
  {
    newNode -> prev = NULL;
    head = newNode;
    return;
  }

  while (temp->next != NULL)
  {
    temp = temp -> next;
  }

  temp -> next = newNode;
  newNode -> prev = temp;

  increaseLength();

  temp = NULL;
  delete temp;
}

template <class T>
void list<T>::pull(T item)
{
  if (getLength() >= 1)
  {
    bool result = false;
    node<T> *temp = head;
    while(temp!=NULL)
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
      if (head->data == temp->data)
      {
        head = temp->next;
      }
      if (temp->next != NULL)
      {
        temp->next->prev = temp->prev;
      }
      if (temp->prev != NULL)
      {
        temp->prev->next = temp->next;
      }

      temp = NULL;
      delete temp;
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

template <class T>
void list<T>::increaseLength()
{
  length++;
}

template <class T>
void list<T>::decreaseLength()
{
  if (length>0)
  {
    length--;
  }
}

template <class T>
int list<T>::getLength()
{
  return length;
}