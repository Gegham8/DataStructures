#include "MaxHeap.h"

int MaxHeap::rightChild(int i) const{
    return 2 * i + 2;
}

int MaxHeap::leftChild(int i) const {
    return 2 * i + 1;
}

int MaxHeap::parent(int i) const {
    return (i - 1) / 2;
}

void MaxHeap::heapify(int index) {
    int largest = index; // parent
    int l = leftChild(index); // left child
    int r = rightChild(index); // right child

    if (this->m_heap.size() > l && this->m_heap[largest] < this->m_heap[l])
    {
        largest = l;
    }

    if (this->m_heap.size() > r && this->m_heap[largest] < this->m_heap[r])
    {
        largest = r;
    }

    if (index != largest){
        std::swap(this->m_heap[index], this->m_heap[largest]);
        heapify(largest);
    }
}

void MaxHeap::print() {
    for (auto& it : m_heap){
        std::cout << it << " " ;
    }
}

void MaxHeap::insert(int index) {
    this->m_heap.push_back(index);

    int i = this->m_heap.size() - 1;
    while (i >= 0 && this->m_heap[i] > this->m_heap[parent(i)]) {
        std::swap(this->m_heap[i], this->m_heap[parent(i)]);
        i = parent(i);
    }
}   

void MaxHeap::deleteKey() {
    if (m_heap.size() == 0) {
        return;
    }
    std::swap(m_heap[0], m_heap[m_heap.size() - 1]);
    m_heap.pop_back();

    heapify(0);
}

int MaxHeap::extractMax() {
    if (m_heap.size() == 0) return -1;
    int max = m_heap[0];
    m_heap[0] = m_heap[m_heap.size() - 1];
    m_heap.pop_back();

    heapify(0);

    return max;
}

void MaxHeap::decreaseKey(int index, int value) {
    m_heap[index] = value;
    while (index >= 0 && m_heap[parent(index)] < m_heap[index]){
        std::swap(m_heap[index], m_heap[parent(index)]);
        index = parent(index);
    }
}