#include "dll.h"

int main() 
{

  list<int> newNode;

  std::cout << std::endl;
  
  newNode.insertFront(5);   //inserted 5 at the beginning
  newNode.insertFront(1);   // then 1
  newNode.insertFront(2);   // then 2
  newNode.insertFront(3);   // then 3
  newNode.insertFront(4);   // then 4

  newNode.printListB();      // printing by order backward direction

  std::cout << std::endl;

  newNode.insertAfter(1,7); // insert 2 after 7

  std::cout << std::endl;

  newNode.printListB();

}