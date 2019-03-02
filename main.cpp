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
  std::cout<<std::endl;

  list<int> newNode2 = newNode;  //copy constructor gets called
  std::cout<< std::endl;
  std::cout<<"Created a second node. Equated to the first node." <<std::endl;
  newNode2.printListB();

  std::cout<< std::endl<<std::endl;
  std::cout<< "inserting 2 and 5 to the second node" << std::endl;
  newNode2.put(2); newNode2.put(5);
  newNode2.printListB();

  std::cout<< std::endl << std::endl;
  std::cout <<"Displaying first node again" << std::endl;
  newNode.printListB();

  std::cout<< std::endl<<std::endl;
  std::cout<< "deleted 1 from the second node" << std::endl;
  newNode2.pull(1);
  newNode2.printListB();
  std::cout << std::endl;
  std::cout << newNode2.getLength();

  std::cout<< std::endl<<std::endl;
  std::cout<< "Displaying first node again" << std::endl;
  newNode.printListB();

  list<int> newNode3(newNode);
}