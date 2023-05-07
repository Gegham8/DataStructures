#pragma once
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
    bool color;
    Node() {};
    Node(int value) : data(value), left(nullptr), right(nullptr),parent(nullptr),color(true) {}
};

class RedBlackTree {
public:
    RedBlackTree();
    ~RedBlackTree();
    void insert(int);
    void print();
    Node* search(int);
    void clear();
    void deleteNode(int);
private:
    Node* minimum(Node*);
    void deleteFix(Node*);
    void rbTransplant(Node*, Node*);
    void delete_node_helper(Node*, int);
    void insertFix(Node*);
    void leftRotate(Node*);
    void rightRotate(Node*);
    void inorder(Node*);
    Node* search_helper(Node*, int);
    void clear_helper(Node*);
private:
    enum Color { BLACK, RED };
    Node* m_root;
    Node* m_TNULL;
};