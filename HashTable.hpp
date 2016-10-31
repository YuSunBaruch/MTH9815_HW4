#ifndef HashTable_HPP
#define HashTable_HPP

#include <vector>

//define hash function
template<typename K>
class Hasher{
public:
	virtual int Hash(K key)=0;
};

//define Predicate
template<typename K>
class EqualityPredicate{
public:
	virtual bool IsEqual(K key1, K key2)=0;
};

//define Hashtable
template<typename K, typename V>
class Hashtable: public Hasher<K>, public EqualityPredicate<K>
{
private:
   std::vector<V> table;
   std::vector<K> keys;
   std::vector<bool> status;
   int count;
   int N;
 public:
    Hashtable(int num);//constructor
    int Hash(K key); //get hash value of key
    bool IsEqual(K key1, K key2); //check if keys are equal
    void Resize(); //resize table
    void Insert(K key, V val);//insert key and val pair
    bool Search(K key);//get value based on key
    bool Remove(K key);// Deletes value by key
    int Size() const {return N;}
};
#include "HashTable.cpp"

#endif