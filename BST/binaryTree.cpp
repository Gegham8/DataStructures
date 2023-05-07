#include "binaryTree.h"

BST* BST::insert(BST* root, int value) {
    if (!root) {
        return new BST(value);
    }

    if (value > root->value) {
        root->right = insert(root->right, value);
    }
    else if (value == root->value) {
        return root;
    }
    else {
        root->left = insert(root->left, value);
    }

    return root;
}

BST* BST::findMin(BST* root) {
    if (!root) {
        return root;
    }
    else if (!root->left) {
        return root;
    }
    else {
        return findMin(root->left);
    }
}

BST* BST::findMax(BST* root) {
    if (root) {
        while (root->right) {
            root = root->right;
        }
        return root;
    } 
    return root;
}

BST* BST::search(BST* root, int value){
    if (!root || root->value == value) {
        return root;
    }
    else if (value > root->value) {
        return search(root->right, value);
    }
    else {
        return search(root->left, value);
    }
}

BST* BST::deleteNode(BST* root, int value){ 
    if (!root) {
        return root;
    }
    if (value > root->value) {
        root->right = deleteNode(root->right, value);
    }
    else if (value < root->value) {
        root->left = deleteNode(root->left, value);
    }
    else {
    if (!root->right) {
        BST* temp = root->left;
        delete root;
        return temp;
    }
    else if (!root->left) {
        BST* temp = root->right;
        delete root;
        return temp;
    }
    BST* node = findMin(root->right);
    root->value = node->value;
    root->right = deleteNode(root->right, node->value);
}
    return root;
}

bool BST::contains(BST* root, int value) {
    if (!root) {
        return false;
    }
    else if (value > root->value) {
        return contains(root->right, value);
    }
    else if (value < root->value) {
        return contains(root->left, value);
    }
    else {
        return true;
    }
}

void BST::inorder(BST* root) {
    if (!root) {
         return;
    }
    inorder(root->left);
    std::cout << root->value << std::endl;
    inorder(root->right);
}

void BST::preorder(BST* root) {
    if (!root) {
        return;
    }
    std::cout << root->value << std::endl;
    preorder(root->left);
    preorder(root->right);
}

void BST::postorder(BST* root) {
    if(!root) { return; }

    std::stack<BST*> s1;
    std::stack<BST*> s2;
    s1.push(root);

    while (!s1.empty()) {
        BST* curr = s1.top();
        s1.pop();
        s2.push(curr);
        if (curr->left) { s1.push(curr->left);}
        if (curr->right) { s1.push(curr->right);}
    }
    while (!s2.empty()) {
        std::cout << s2.top()->value << " ";
        s2.pop();
    }

    
}

bool BST::same(BST* p, BST* q) {
    if (!p && !q) {
        return true;
    }
    else if (!p || !q) {
        return false;
    }
    return (p->value == q->value) && same(p->left, q->left) && same(p->right, q->right);
}