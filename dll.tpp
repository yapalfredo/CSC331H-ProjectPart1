
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
  length++;
  delete temp;
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
    //std::cout << "Found! \n";
 
    newNode -> data = item;
    newNode -> next = temp -> next; 
    temp -> next = newNode;
    newNode -> prev = temp;
    
    if (newNode->next != NULL)
    {
      newNode -> next -> prev = newNode;
    }

  }
  else
  {
    std::cout << "Not found! \n";
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
  node<T> *temp = head;
  while(temp!=NULL)
  {
    std::cout << temp->data << " ";
    temp = temp->next;
  }

  temp = NULL;
  delete temp;
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