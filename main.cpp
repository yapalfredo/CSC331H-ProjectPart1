#include "dll.h"

int main() 
{
  std::cout << "Hello World!\n";

  list<int> newNode;

  newNode.insertFront(5);
  newNode.insertFront(1);
  newNode.insertFront(2);
  newNode.insertFront(3);
  newNode.insertFront(4);
  newNode.printList();

  std::cout << "\n\n";
  newNode.insertAfter(4,5);

  

}