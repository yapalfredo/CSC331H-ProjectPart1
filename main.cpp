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
  

  std::cout << std::endl << std::endl;

  std::cout << "Insert 7 after 1";
  newNode.insertAfter(1,7); // insert 7 after 1

  std::cout << std::endl;

  newNode.printListB();
  
  std::cout << std::endl << std::endl;
  std::cout << "The length of the list is: " << newNode.getLength();
  
  std::cout << std::endl << std::endl;
  std::cout << "delete 7 in the list" << std::endl;
  newNode.pull(7); //delete 
  newNode.printListB();
  std::cout<< std::endl << "\nThe length of the list is: " << newNode.getLength();

  std::cout << std::endl << std::endl;
  std::cout << "insert 9 at the end" << std::endl;
  newNode.insertEnd(9); //delete 
  newNode.printListB();
  std::cout<< std::endl << "\nThe length of the list is: " << newNode.getLength();

 list<int> newNode2 = newNode;
 std::cout<< std::endl;
 newNode2.printListB();
}