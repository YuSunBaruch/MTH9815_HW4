//define node class

#ifndef Node_HPP
#define Node_HPP

//#include <tr1/memory>
#include <boost/shared_ptr.hpp>
#include <boost/pointer_cast.hpp>

template<typename T>
class Node{
protected:
	T val;
	boost::shared_ptr<Node<T> > next_ptr;
public:
	Node(); //default constructor
	Node(const T& val_, const boost::shared_ptr<Node<T> >& ptr_); //parameter constructor
	//getter and setter of val
	void Val(const T& val_){val=val_;}
	T Val() const {return val;}
	//getter and setter of next_ptr
	void Ptr(const boost::shared_ptr<Node<T> >& ptr_){next_ptr=ptr_;}
	boost::shared_ptr<Node<T> > Ptr() const {return next_ptr;}
	virtual ~Node(){} //Destructor
};

template<typename T>
class DNode: public Node<T>
{
private:
	boost::shared_ptr<Node<T> > prev_ptr;
public:
	DNode();//default constructor
	DNode(const T& val_, const boost::shared_ptr<Node<T> >& nextPtr, const boost::shared_ptr<Node<T> >& prevPtr);
	//getter and setter of prev_ptr
	void PrevPtr(const boost::shared_ptr<Node<T> >& ptr_){prev_ptr=ptr_;}
	boost::shared_ptr<Node<T> > PrevPtr() const {return prev_ptr;}
	virtual ~DNode(){}
};

#include "Node.cpp"
#endif