//implement Node.hpp
#ifndef Node_CPP
#define Node_CPP

#include "Node.hpp"

template<typename T>
Node<T>::Node():val(0),next_ptr(nullptr){}

template<typename T>
Node<T>::Node(const T& val_,const boost::shared_ptr<Node<T> >& ptr_):val(val_),next_ptr(ptr_){}

template<typename T>
DNode<T>::DNode(): Node<T>(),prev_ptr(nullptr){}

template<typename T>
DNode<T>::DNode(const T& val_, const boost::shared_ptr<Node<T> >& nextPtr, const boost::shared_ptr<Node<T> >& prevPtr):
                Node<T>(val_,nextPtr), prev_ptr(prevPtr){}

#endif