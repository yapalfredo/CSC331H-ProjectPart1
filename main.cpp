#include "dll.h"

int main() 
{
  list<int> newNode;

  std::cout << std::endl;
  
  newNode.put(5);   // inserted 5 at the beginning
  newNode.put(1);   // then 1
  newNode.put(2);   // then 2
  newNode.put(3);   // then 3
  newNode.put(4);   // then 4

  newNode.printListB();      // printing by order in backward direction
  

  std::cout << std::endl;

  newNode.insertAfter(1,7); // insert 2 after 7

  std::cout << std::endl;

  newNode.printListB();
  
  std::cout << std::endl << std::endl;
  std::cout << "The length of the list is: " << newNode.getLength();
  
  std::cout << std::endl << std::endl;
  newNode.pull(7); //delete 
  newNode.printListB();
  std::cout << "\nThe length of the list is: " << newNode.getLength();
}