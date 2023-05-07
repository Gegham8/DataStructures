#pragma once
#include <vector>
#include <iostream>

class MaxHeap {
public:
    void insert(int);
    void deleteKey();
    void heapify(int);
    void print();
    int extractMax();
    void decreaseKey(int, int);
private:
    std::vector<int> m_heap;
    int parent(int) const ;
    int leftChild(int) const ;
    int rightChild(int) const ;
};