#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <functional>
#include <vector>
#include <string>

using namespace std;
template<class K, class V>
class HashTable {
  private:
    int capacity;
    int size;
    vector<vector<pair<K, V>>> buckets;
    int Hash(K key) {
      return hash<K>{}(key) % capacity;
    }

  public:
    explicit HashTable(int capacity = 101): capacity(capacity), size(0) { buckets.resize(capacity);}
    
    bool Exist(K key, V value) {
      int index = Hash(key);
      vector<pair<K, V>>& chain = buckets.at(index);

      for(auto& pair: chain) 
        if(pair.first == key && pair.second == value)
          return true;
      return false;
    }

    bool HasKey(K key){
      int index = Hash(key);
      for(auto& pair: buckets.at(index)) 
        if(pair.first == key)
          return true;
      return false;
    }

    bool Insert(K key, V value){
      int index = Hash(key);

      if(!HasKey(key) && size < capacity) {
        buckets.at(index).push_back(pair<K, V>(key, value));
        size++;
        return true;
      }
      return false;
    }

    bool Remove(K key){
      int index = Hash(key);
      if(HasKey(key)) {
        vector<pair<K, V>>& chain = buckets.at(index);
        for(auto i = chain.begin(); i != chain.end(); ++i){
          if(i->first == key){
            chain.erase(i);
            size--;
            return true;
          }
        }
      }
      return false;
    }

    void Clear() {
      for(auto& chain: buckets){
        chain.clear();
      }
      this->size = 0;
    }

    void Resize(int capacity){
      Clear();
      buckets.resize(capacity);
      this->capacity = capacity;
    }

    int GetSize() {
      return this->size;
    }

    int GetCapacity() {
      return this->capacity;
    }
};

#endif