//implement linkedlist
#ifndef LinkedList_CPP
#define LinkedList_CPP

#include "LinkedList.hpp"

template<typename T>
LinkedList<T>::LinkedList(): list_ptr(nullptr){}
	
template<typename T>
LinkedList<T>::LinkedList(const boost::shared_ptr<Node<T> >& head):list_ptr(head){}

template<typename T>
void LinkedList<T>::Add(T value){
	//the next_ptr for last node to add
	boost::shared_ptr<Node<T> > tail(nullptr);
	//point to current node
	boost::shared_ptr<Node<T> > current(list_ptr);
	if(!current){
		boost::shared_ptr<Node<T> > temp(new Node<T>(value,tail));
		list_ptr=temp;
		return;
	}
	//go to the last node in original list
	while(current && current->Ptr()){current=current->Ptr();}
	//construct pointer point to the new tail node
	boost::shared_ptr<Node<T> > last_ptr(new Node<T>(value,tail));
	//set the next_ptr for second last node
	current->Ptr(last_ptr);
}

template<typename T>
void LinkedList<T>::Insert(T value, int index){
	if(index>=Size()) Add(value);
	int count=0;//count if reach specified index
	//point to current node
	boost::shared_ptr<Node<T> > current(list_ptr);
	//point to previous node
	boost::shared_ptr<Node<T> > previous(nullptr);
	if(index==0){
		boost::shared_ptr<Node<T> > temp=list_ptr;
		boost::shared_ptr<Node<T> > temp2(new Node<T>(value,temp));
		list_ptr=temp2;
		return;
	}
	while(count<index){
		previous=current;//update previous
		current=current->Ptr();//update current
		++count;//increment count
	}
	//next_ptr for the node to add
	boost::shared_ptr<Node<T> > ptr_to_add(current);
	//point to the node to add
	boost::shared_ptr<Node<T> > next_node_ptr(new Node<T>(value,ptr_to_add));
	//update the next_ptr for previous
	previous->Ptr(next_node_ptr);
}

template<typename T>
T LinkedList<T>::Get(int index){
	int count=0;//count if reach index
	//point to current node
	boost::shared_ptr<Node<T> > current(list_ptr);
	while(count<index){
		++count;
		current=current->Ptr();
	}
	return current->Val();
}

template<typename T>
int LinkedList<T>::IndexOf(T value){
	bool find=false;//check if a match is found
	int index=0;//record index
	boost::shared_ptr<Node<T> > current=list_ptr;//point to current node
	//if it matches with first element, return 0
	if(value==current->Val()) return index;
	while(current && value!=current->Val()){
       ++index;
       current=current->Ptr();
       if(current){
       	if(value==current->Val()) find=true;
       }
	}
	if(find) return index;
	return -1;
}

template<typename T>
T LinkedList<T>::Remove(int index){
    if(index>=Size()) index=Size()-1;
    T value; //record value to return
    if(index==0) {
    	//get value to return
    	value=list_ptr->Val();
    	//update list_ptr
    	list_ptr=list_ptr->Ptr();
    	return value;
    }
    int count=0; //record if reach index
    boost::shared_ptr<Node<T> > current=list_ptr; //point to current node
    boost::shared_ptr<Node<T> > previous(nullptr);//point to previous node
    while(count<index){
    	previous=current;//update previous
    	current=current->Ptr(); //update current
    	++count;//update count
    }
    value=current->Val();//get the value to remove
    previous->Ptr(current->Ptr());//remove the node at current
    return value;
}

template<typename T>
ListIterator<T> LinkedList<T>::Iterator(){
	ListIterator<T> result(list_ptr);
	return result;
}
   
template<typename T>
int LinkedList<T>::Size(){
	if(!list_ptr) return 0;
	int count=0;//count the size
	boost::shared_ptr<Node<T> > current=list_ptr;//point to current node
	while(current){
		++count;
		current=current->Ptr();
	}
	return count;
}

template<typename T>
ListIterator<T>::ListIterator():iterator(nullptr){}

template<typename T>
ListIterator<T>::ListIterator(const boost::shared_ptr<Node<T> >& src): iterator(src){}

template<typename T>
bool ListIterator<T>::HasNext(){
	if(iterator->Ptr()) return true;
	else return false;
}

template<typename T>
T ListIterator<T>::Next(){
	if(!HasNext()) return 0;
	boost::shared_ptr<Node<T> > nextPtr=iterator->Ptr();
    return nextPtr->Val();
}


#endif