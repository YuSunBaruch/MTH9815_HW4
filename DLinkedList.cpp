//implement DLinkedList
#ifndef DLinkedList_CPP
#define DLinkedList_CPP

#include "DLinkedList.hpp"

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(): LinkedList<T>(){}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const boost::shared_ptr<DNode<T> >& head):LinkedList<T>(){
  LinkedList<T>::list_ptr=boost::dynamic_pointer_cast<Node<T> >(head);
}

template<typename T>
boost::shared_ptr<DNode<T> > DoublyLinkedList<T>::Head(){
	boost::shared_ptr<DNode<T> > result=boost::dynamic_pointer_cast<DNode<T> >(LinkedList<T>::list_ptr);
	return result;
}

template<typename T>
void DoublyLinkedList<T>::Add(T value){
	if(!LinkedList<T>::list_ptr){
	  boost::shared_ptr<DNode<T> > new_dhead(new DNode<T>(value,LinkedList<T>::list_ptr,nullptr));
      LinkedList<T>::list_ptr=boost::dynamic_pointer_cast<Node<T> >(new_dhead);
   }
   else{
   	  boost::shared_ptr<Node<T> > current(LinkedList<T>::list_ptr); //point to current node
   	  while(current->Ptr()){current=current->Ptr();}//update current
   	  boost::shared_ptr<DNode<T> > new_dhead(new DNode<T>(value, nullptr,current));//construct last dnode
   	  boost::shared_ptr<Node<T> > new_head=boost::dynamic_pointer_cast<Node<T> >(new_dhead); //convert to Node pointer
   	  current->Ptr(new_head);
   }
}

template<typename T>
void DoublyLinkedList<T>::Insert(T value, int index){
	if(index==0) Add(value);
    if(index>=LinkedList<T>::Size()) index=LinkedList<T>::Size()-1;
    boost::shared_ptr<Node<T> > current=LinkedList<T>::list_ptr; //point to current node
    int count=0; //check if reach index
    while(count<index){
    	++count; //update count
    	current=current->Ptr(); //update current pointer
    }
    boost::shared_ptr<DNode<T> > dcurrent=boost::dynamic_pointer_cast<DNode<T> >(current); //convert to DNode pointer
    boost::shared_ptr<Node<T> > prev=dcurrent->PrevPtr(); //get the prev pointer
    boost::shared_ptr<DNode<T> > new_dnode(new DNode<T>(value,current,prev)); //construct new dnode to add
    boost::shared_ptr<Node<T> > new_node=boost::dynamic_pointer_cast<Node<T> >(new_dnode); //convert to node pointer
    prev->Ptr(new_node); //link with prev pointer
    dcurrent->PrevPtr(new_node); //link with dcurrent pointer
}

template<typename T>
T DoublyLinkedList<T>::Remove(int index){
	T result; //result to return
    if(index>LinkedList<T>::Size()-1) index=LinkedList<T>::Size()-1;
    boost::shared_ptr<Node<T> > current=LinkedList<T>::list_ptr; //point to current node
    int count=0; //check if reach index
    while(count<index){
    	++count; //update count
    	current=current->Ptr(); //update current pointer
    } 
    result=current->Val(); //get the result to return
    boost::shared_ptr<DNode<T> > dcurrent=boost::dynamic_pointer_cast<DNode<T> >(current); //convert to DNode pointer
    boost::shared_ptr<Node<T> > prev=dcurrent->PrevPtr(); //get the previous node
    if(index==LinkedList<T>::Size()-1){
       prev->Ptr(nullptr); //set next pointer for prev to be nullptr
       dcurrent->PrevPtr(nullptr); //set previous pointer for current to be nullptr
       return result; //return result
    }
    prev->Ptr(current->Ptr());//reset next pointer for prev
    boost::shared_ptr<Node<T> > nextNode=current->Ptr(); //get next pointer
    boost::shared_ptr<DNode<T> > nextDnode=boost::dynamic_pointer_cast<DNode<T> >(nextNode); //convert to DNode pointer
    nextDnode->PrevPtr(prev);//reset previous pointer for next node
    return result;
}


#endif