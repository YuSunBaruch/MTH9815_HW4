#include <iostream>
#include <boost/shared_ptr.hpp>
#include "LinkedList.hpp"
#include "DLinkedList.hpp"

int main(){
	//test LinkedList
	std::cout<<"LinkedList:\n";
	LinkedList<double> lst;
	lst.Add(1.1);
	lst.Add(3.3);
	lst.Add(9.2);
	lst.Insert(8.5,1);
	std::cout<<"lst at position 2: "<<lst.Get(2)<<std::endl;
	std::cout<<"Index of element 9.2: "<<lst.IndexOf(9.2)<<"\n";
	std::cout<<"Remove element at position 1: "<<lst.Remove(1)<<"\n";
	ListIterator<double> lstiter=lst.Iterator();
	std::cout<<"Get size of lst: "<<lst.Size()<<"\n";
	std::cout<<std::boolalpha<<"Does the iterator has next element? "<<lstiter.HasNext()<<"\n";
	std::cout<<"Give next element: "<<lstiter.Next()<<"\n";

    	//test doublylinkedlist
    	std::cout<<"DoublyLinkedList:\n";
    	DoublyLinkedList<double> dlst;
    	dlst.Add(1.1);
    	dlst.Add(3.3);
    	dlst.Add(9.2);
    	dlst.Insert(8.5,1);
    	std::cout<<"dlst at position 2: "<<dlst.Get(2)<<std::endl;
    	std::cout<<"Index of element 9.2: "<<dlst.IndexOf(9.2)<<"\n";
    	std::cout<<"Remove element at position 1: "<<dlst.Remove(1)<<"\n";
    	ListIterator<double> dlstiter=dlst.Iterator();
    	std::cout<<"Get size of dlst: "<<dlst.Size()<<"\n";
    	std::cout<<std::boolalpha<<"Does the iterator has next element? "<<dlstiter.HasNext()<<"\n";
    	std::cout<<"Give next element: "<<dlstiter.Next()<<"\n";

	return 0;
}