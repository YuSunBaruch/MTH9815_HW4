//define DLinkedList
#ifndef DLinkedList_HPP
#define DLinkedList_HPP

#include "LinkedList.hpp"

template<typename T>
class DoublyLinkedList: public LinkedList<T>{
public:
	DoublyLinkedList();
	DoublyLinkedList(const boost::shared_ptr<DNode<T> >& head);
	virtual boost::shared_ptr<DNode<T> > Head();
	//add element at the end
	virtual void Add(T value);
	//add specified element at specified index
	virtual void Insert(T value, int index);
	//remove element at specified index
	virtual T Remove(int index);
	//others are inheritated 
	virtual ~DoublyLinkedList(){}
};

#include "DLinkedList.cpp"

#endif