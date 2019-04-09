#include "dll.h"

int main()
{
	list<int> newNode;

	std::cout << std::endl;

	newNode.insertFront(5);   // inserted 5 at the beginning
	newNode.insertFront(1);   // then 1
	newNode.insertFront(2);   // then 2
	newNode.insertFront(3);   // then 3
	newNode.insertFront(4);   // then 4
	newNode.printListB();      // printing by order in backward direction

	std::cout << "Insert 7 after 1" << std::endl;
	newNode.insertAfter(1, 7); // insert 7 after 1
	std::cout << std::endl;
	newNode.printListB();

	std::cout << "The length of the list is: " << newNode.getLength();

	std::cout << std::endl << std::endl;
	std::cout << "delete 7 in the list" << std::endl;
	newNode.deleteNode(7); //delete 
	newNode.printListB();
	std::cout << "\nThe length of the list is: " << newNode.getLength();

	std::cout << std::endl << std::endl;
	std::cout << "insert 9 at the end" << std::endl;
	newNode.insertEnd(9);
	newNode.printListB();
	std::cout << "\nThe length of the list is: " << newNode.getLength();
	std::cout << std::endl;

	list<int> newNode2 = newNode;  //copy constructor gets called
	std::cout << std::endl;
	std::cout << "Created a second node. Equated to the first node." << std::endl;
	newNode2.printListB();

	std::cout << std::endl << std::endl;
	std::cout << "inserting 2 and 5 to the second node" << std::endl;
	newNode2.insertFront(2); newNode2.insertFront(5);
	newNode2.printListB();

	std::cout << std::endl << std::endl;
	std::cout << "Displaying first node again" << std::endl;
	newNode.printListB();


	std::cout << std::endl << std::endl;
	std::cout << "deleted 1 from the second node" << std::endl;
	newNode2.deleteNode(1);

	newNode2.printListB();
	std::cout << std::endl;
	std::cout << "The length is: " << newNode2.getLength();

	std::cout << std::endl << std::endl;
	std::cout << "Displaying first node again" << std::endl;
	newNode.printListB();

	std::cout << std::endl << std::endl;
	std::cout << "Inserteed 8,6,7,0 to first node" << std::endl;
	newNode.insertFront(8);
	newNode.insertFront(6);
	newNode.insertFront(7);
	newNode.insertFront(0);
	newNode.printListB();
	std::cout << std::endl<<"Length of the first node is: "<< newNode.getLength();

	std::cout << std::endl << std::endl;
	list<int> newNode3;

	newNode3.insertFront(1);
	newNode3.insertFront(3);
	newNode3.insertFront(5);
	newNode3.insertFront(7);
	std::cout << "Created 3rd Node" << std::endl;
	newNode3.printListB();

	std::cout << std::endl;
	newNode3 = newNode;

	std::cout << std::endl;
	std::cout << "assigning 3rd Node equal to first node" << std::endl;
	newNode3.printListB();
	std::cout << std::endl;
	std::cout << "The length of 3rd node is: " << newNode3.getLength() << std::endl << std::endl;

	std::cout << std::endl;

	std::cout << "Traversing 3rd node via iterator head-> last node" << std::endl;
	auto itr = newNode3.begin();
	for (int i = 0; i < newNode3.getLength(); i++)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << "Traversing 3rd node via iterator last node -> head" << std::endl;
	itr = newNode3.end();
	for (int i = newNode3.getLength(); i > 0; i--)
	{
		std::cout << *itr << " ";
		itr--;

	}
	std::cout << std::endl << std::endl;
	



	system("pause");
	return 0;
}
