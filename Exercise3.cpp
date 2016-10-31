#include <iostream>
#include <string>
#include "HashTable.hpp"

int main(){
	Hashtable<long,std::string> ht(5);
 	try{
    	ht.Insert(1,"abc");
    	ht.Insert(2,"mmn");
    	ht.Insert(3,"hello");
    	ht.Insert(4,"bal");
    	ht.Insert(5,"heheww");
    	std::cout<<"Size of table: "<<ht.Size()<<"\n";
    	std::cout<<std::boolalpha<<"Is there a key 1: "<<ht.Search(1)<<"\n";
	std::cout<<"Remove key 1: "<<ht.Remove(1)<<"\n";
	std::cout<<std::boolalpha<<"Is there a key 1: "<<ht.Search(1)<<"\n";
    	ht.Insert(1,"hall");
    }
    catch(...){
    	std::cout<<"There is an error.\n";
    }

	return 0;
}