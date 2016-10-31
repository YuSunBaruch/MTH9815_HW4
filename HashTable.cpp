    //implement Hashtable classes
    #ifndef Hashtable_CPP
    #define Hashtable_CPP
    
    #include "HashTable.hpp"
    #include <algorithm>

    template<typename K, typename V>
    Hashtable<K,V>::Hashtable(int num):count(0),N(num){
    	std::vector<V> temp(N);
    	std::vector<K> temp3(N);
    	keys=temp3;//initialize keys
    	table=temp;//initialize table
    	std::vector<bool> temp2(N,false); //false means no data
    	status=temp2;//initialize status
    }
    template<typename K, typename V>
    int Hashtable<K,V>::Hash(K key){
    	int knum=(int)key;
    	return knum%N;
    }
    template<typename K, typename V>
    bool Hashtable<K,V>::IsEqual(K key1, K key2){
    	if(key1==key2) return true;
    	else return false;
    }
    template<typename K, typename V>
    void Hashtable<K,V>::Resize(){
    	N*=2; //increase size
    	std::vector<V> temp1(table); //copy table to temp1
    	std::vector<bool> temp2(status); //copy status to temp2
    	std::vector<K> temp3(keys);//copy keys to temp3
    	table.clear(); status.clear(); keys.clear(); //clear up
    	table.resize(N); status.resize(N); keys.resize(N); //resie
    	std::fill(status.begin(),status.end(),false); //fill status
    	
    	for(int i=0;i<temp1.size();++i){
    		if(temp2[i]){
    			K thekey=temp3[i]; //get the key
    			int index=Hash(thekey); //get the index
    			status[index]=true; //set corresponding status to true
    			keys[index]=thekey; //set thekey to keys
    			table[index]=temp1[i]; //set corresponding value to table
    		}
    	}
    }
    template<typename K, typename V>
    void Hashtable<K,V>::Insert(K key, V val){
    	for(int i=0;i<status.size();++i){
    		//check if exist duplicate keys
    		if(status[i] && IsEqual(key,keys[i])){
    			throw "Duplicate keys";
    		}
    	}
    	//increase count by 1
    	++count;
    	//if the occupancy rate is higher than 0.6, resize
    	if(double(count)/double(N)>0.6) Resize();
    	//convert key to index
        int index=Hash(key);
        //if not occupied, store value and key at index
        if(!status[index]){
        	status[index]=true;
        	keys[index]=key;
        	table[index]=val;
        }
        else{
        	//if occupied
        	while(status[index]){
        		//go to check next available position
        		index=(index+1)%N;
        		if(!status[index]){
        			status[index]=true; //the index is to be occupied
        			keys[index]=key; //store key
        			table[index]=val; //store value
        			break;
        		}
        	}
        }
    }
    template<typename K, typename V>
    bool Hashtable<K,V>::Search(K key){
    	int index=Hash(key);
    	V result;
    	if(status[index]==false){
    		return false;
    	}
    	int num=0;
    	while(status[index]){
    		if(IsEqual(key,keys[index])) return true;
    		num++;
    		if(num==N) return false;
    		index=(index+1)%N;
    	}
    	return false;
    }

    template<typename K, typename V>
    bool Hashtable<K,V>::Remove(K key){
	int index = Hash(key);
	if(status[index]==false){
    		return false;
    	}
	while(status[index]){
		table.erase(std::find(table.begin(),table.end(),table[index]));
		keys.erase(std::find(keys.begin(),keys.end(),keys[index]));
		status.erase(std::find(status.begin(),status.end(),status[index]));
		return true;
	}
	return false;
    }
    #endif