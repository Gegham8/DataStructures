#include "RedBlackTree.h"

int main() {
    RedBlackTree a;
    a.insert(1);
    a.insert(188);
    a.insert(465);
    a.insert(100);
    a.insert(881);
    a.deleteNode(188);
    a.deleteNode(1);
    a.clear();
    a.insert(1);
    a.deleteNode(1);
    a.print();
}