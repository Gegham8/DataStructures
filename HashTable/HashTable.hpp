#include "HashTable.h"

template <typename K, typename T>
int HashTable<K, T>::hashFunction(const K& key){
    return key % m_hash.size();
}

template <typename K, typename T>
void HashTable<K, T>::insert(const K& key, const T& value){
    int index = hashFunction(key);
    for (int i = 0; i < m_hash.size(); ++i) {
        for (auto& it : m_hash[i]){
            if (it.first == key) {
                it.second = value;
                return;
            }
        }
    }
    m_hash[index].push_back(std::make_pair(key, value));
}

template <typename K, typename T>
const T HashTable<K, T>::find(const K& key) {
    T returnValue;
    int index = this->hashFunction(key);
    for (auto& it : m_hash[index]) {
        if (it.first == key) {
            returnValue =  it.second;
        }
    }
    return returnValue;
}

template <typename K, typename T>
bool HashTable<K, T>::empty() const {
    for (int i = 0; i < m_hash.size(); ++i) {
        if (m_hash[i].empty()) {
            return true;
        }
    }
    return false;
}

template <typename K, typename T>
bool HashTable<K, T>::contains(const K& key) const {
    for (int i = 0; i < m_hash.size(); ++i) {
        for (auto& it : m_hash[i]) {
            if (it.first == key){
                return true;
            }
        }
    }
    return false;
}
template <typename K, typename T>
void HashTable<K, T>::emplace(const K& key, const T& value){
    size_t index = hashFunction(key);
    auto& bucket = m_hash[index];
    for (auto& it : bucket) {
        if (it.first == key) {
            it.second = value;
            return;
        }
    }
    bucket.emplace_back(key, value);
}

template <typename K, typename T>
size_t HashTable<K, T>::size() const {
    size_t sizeofHash = 0;
    for (int i = 0; i < m_hash.size(); ++i){
        for (auto& it : m_hash[i]){
            ++sizeofHash;
        }
    }
    return sizeofHash;
}

template <typename K, typename T>
void HashTable<K, T>::deleteKey(const K& key) {
    size_t index = hashFunction(key);
    auto& bucket = m_hash[index];
    for (auto it = bucket.begin(); it != bucket.end(); ++it){
        if (it->first == key){
            it = bucket.erase(it);
        }
    }
}

template <typename K, typename T>
void HashTable<K, T>::clear() {
    for (int i = 0; i < m_hash.size(); ++i){
        m_hash[i].clear();
    }
}

template <typename K, typename T>
HashTable<K, T>::HashTable(const HashTable& other){
    if (this->m_hash == other.m_hash) {
        return;
    }
    this->m_hash.resize(other.m_hash.size());
    for (int i = 0; i < other.m_hash.size(); ++i){
            this->m_hash[i] = other.m_hash[i];
    }
}

template <typename K, typename T>
HashTable<K, T>::HashTable(size_t size) {
    this->m_hash.resize(size);
}

template <typename K, typename T>
HashTable<K, T>::HashTable(HashTable&& other) : m_hash(std::move(other.m_hash)) {}

template <typename K, typename T>
HashTable<K, T> HashTable<K, T>::operator =(HashTable&& other){
    if (this->m_hash != other.m_hash){
        m_hash(std::move(other.m_hash));
    }
    return *this;
}

template <typename K, typename T>
HashTable<K, T> HashTable<K, T>::operator=(const HashTable&  obj) {
    if (this->m_hash != obj.m_hash) {
        this->m_hash.resize(obj.m_hash.size());
        for (int i = 0; i < obj.m_hash.size(); ++i){
            this->m_hash[i] = obj.m_hash[i];
        }
        return *this;
    }
}

template <typename K, typename T>
T HashTable<K, T>::operator[](const K& key) {
    int index = hashFunction(key);
    auto bucket = m_hash[index];
    for (auto& it : bucket) {
        if (it.first == key){
            return it.second;
        }
    }
    throw std::invalid_argument("Invalid argument"); 
}

