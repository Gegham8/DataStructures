#pragma once
#include <iostream>
#include <vector>
#include <list>

template <typename K, typename T>
class HashTable {
private:
    int hashFunction(const K&);
public:
    HashTable() = default;
    HashTable(size_t = 1);
    HashTable(const HashTable&);
    HashTable(HashTable&&);
    ~HashTable() {};
    void insert(const K&, const T&); 
    void deleteKey(const K&);
    const T find(const K&) ;
    bool empty() const;
    bool contains(const K&) const;
    size_t size() const;
    void clear();
    void emplace(const K&, const T&);
public:
    T operator[](const K&);
    HashTable<K, T> operator = (const HashTable&);
    HashTable<K, T> operator = (HashTable&&);
public:
    friend std::ostream& operator<<(std::ostream& os, const HashTable<K, T>& other) {
        for (int i = 0; i < other.m_hash.size(); ++i) {
            for (auto& it : other.m_hash[i]){
                os << '[' << it.first << ',' << it.second << ']';
            }
        }
        return os;
    }
private:
    std::vector<std::list<std::pair<K, T>>> m_hash;
};
