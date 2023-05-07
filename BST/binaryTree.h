#include <iostream>
#include <stack>
class BST {
public: 
    BST() = default;
    BST(int value) : value(value), left(nullptr), right(nullptr) {}
    BST* insert(BST*, int);
    void inorder(BST*);
    BST* findMin(BST*);
    BST* findMax(BST*);
    BST* search(BST*, int);
    BST* deleteNode(BST*, int);
    void preorder(BST*);
    bool contains(BST*, int);
    void postorder(BST*);
    bool same(BST*, BST*);
    int value;

private: 
    BST* left;
    BST* right;
};