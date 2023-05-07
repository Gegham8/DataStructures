// #include "HashTable.h"
#include "HashTable.hpp"
int main() {
    int a = 2;
    HashTable<int, char> hash(2);
    hash.insert(19, 'e');
    hash.insert(88, 'd');
    hash.insert(77, 'l');
    hash.insert(5, 'p');
    hash.emplace(69, 'h');
    std::cout << hash.find(5) << std::endl;


}