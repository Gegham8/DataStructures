#include <iostream>
#include "binaryTree.h"


int main() {

    
    BST root;
    root.insert(&root, 58);
    root.insert(&root, 14);
    root.insert(&root, 76);
    root.insert(&root, 6);
    root.insert(&root, 43);
    root.insert(&root, 63);
    root.insert(&root, 78);
    root.insert(&root, 11);
    root.insert(&root, 61);
    root.insert(&root, 64);
    root.inorder(&root);
}