//define LinkedList class
#ifndef LinkedList_HPP
#define LinkedList_HPP

#include "Node.hpp"

template<typename T>
class ListIterator;

template<typename T>
class LinkedList{
protected:
	boost::shared_ptr<Node<T> > list_ptr;
public:
	//default constructor
	LinkedList();
	//constructor with parameter
	LinkedList(const boost::shared_ptr<Node<T> >& head);
	virtual boost::shared_ptr<Node<T> > Head() const{return list_ptr;}
	//add element at the end
	virtual void Add(T value);
	//add specified element at specified index
	virtual void Insert(T value, int index);
	//get element at specified index
	virtual T Get(int index);
	//get index of specified element
	virtual int IndexOf(T value);
	//remove element at specified index
	virtual T Remove(int index);
	//return iterator on this list
    	virtual ListIterator<T> Iterator();
    	//return size of the list
    	virtual int Size();
    	virtual ~LinkedList(){}
};

template<typename T>
class ListIterator{
private:
	boost::shared_ptr<Node<T> > iterator;
public:
	//default constructor
	ListIterator();
	//constructor with parameter
	ListIterator(const boost::shared_ptr<Node<T> >& src);
	//return whether there is another element
	bool HasNext();
	//return next element
	T Next();
	virtual ~ListIterator(){}
};

#include "LinkedList.cpp"
#endif