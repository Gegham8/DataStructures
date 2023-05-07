#include "RedBlackTree.h"
void RedBlackTree::leftRotate(Node* node) {
    Node* x = node->right;
    node->right = x->left;
    if (x->left) {
        x->left->parent = node;
    }
    x->parent = node->parent;
    if (!x->parent) {
        m_root = x;
    } else if (node == node->parent->left) {
        node->parent->left = x;
    } else {
        node->parent->right = x;
    }
    x->left = node;
    node->parent = x;
}

void RedBlackTree::rightRotate(Node* node){
    Node* x = node->left;
    node->left = x->right;
    if (x->right) {
        x->right->parent = node;
    }
    x->parent = node->parent;
    if (!x->parent) {
        m_root = x;
    } else if (node == node->parent->left) {
        node->parent->left = x;
    } else {
        node->parent->right = x;
    }
    x->right = node;
    node->parent = x;
}

void RedBlackTree::insertFix(Node* node) {
    Node* x;
    while (node->parent->color == RED) {
      if (node->parent == node->parent->parent->right) {
        x = node->parent->parent->left;
        if (x->color == 1) {
          x->color = 0;
          node->parent->color = 0;
          node->parent->parent->color = 1;
          node = node->parent->parent;
        } else {
          if (node == node->parent->left) {
            node = node->parent;
            rightRotate(node);
          }
          node->parent->color = 0;
          node->parent->parent->color = 1;
          leftRotate(node->parent->parent);
        }
      } else {
        x = node->parent->parent->right;
        if (x->color == RED) {
            x->color = BLACK;
            node->parent->color = BLACK;
            node->parent->parent->color = RED;
            node = node->parent->parent;
        } else {
          if (node == node->parent->right) {
                node = node->parent;
                leftRotate(node);
            }
            node->parent->color = 0;
            node->parent->parent->color = 1;
            rightRotate(node->parent->parent);
        }
      }
      if (node == m_root) {
        break;
      }
    }
    m_root->color = 0;

}

void RedBlackTree::rbTransplant(Node* parent, Node* child) {
    if (parent->parent == nullptr) {
        m_root = child;
    } else if (parent == parent->parent->left) {
        parent->parent->left = child;
    } else {
        parent->parent->right = child;
    }
    child->parent = parent->parent;
}

void RedBlackTree::deleteFix(Node* node) {
    Node* x;
    while (node != m_root && node->color == BLACK) {
        if (node == node->parent->left) {
            x = node->parent->right;
            if (x->color == RED) {
                x->color = BLACK;
                node->parent->color = RED;
                leftRotate(node->parent);
                x = node->parent->right;
            }

            if (x->left->color == BLACK && x->right->color == BLACK) {
                x->color = RED;
                node = node->parent;
            } else {
                if (x->right->color == BLACK) {
                    x->left->color = BLACK;
                    x->color = RED;
                    rightRotate(x);
                    x = node->parent->right;
                }
                x->color = node->parent->color;
                node->parent->color = BLACK;
                x->right->color = BLACK;
                leftRotate(node->parent);
                node = m_root;
            }
        } 
        else {
            x = node->parent->left;
            if (x->color == RED) {
                x->color = BLACK;
                node->parent->color = RED;
                rightRotate(node->parent);
                x = node->parent->left;
            }

            if (x->right->color == BLACK && x->right->color == BLACK) {
                x->color = RED;
                node = node->parent;
            } else {
                if (x->left->color == BLACK) {
                    node->right->color = BLACK;
                    x->color = RED;
                    leftRotate(x);
                    x = node->parent->left;
                }

                x->color = node->parent->color;
                node->parent->color = BLACK;
                x->left->color = BLACK;
                rightRotate(node->parent);
                node = m_root;
            }
        }
    }
    node->color = BLACK;

}

void RedBlackTree::delete_node_helper(Node* node, int value) {
    Node* x = m_TNULL;
    Node* y = nullptr;
    Node* z = nullptr;
    while (node != m_TNULL) {
        if (node->data == value) {
            x = node;
            break;
        } else if (node->data > value) {
            node = node->left;
        } else {
            node = node->right;
        }
    }

    if (x == m_TNULL) {
        std::cout << "Not found" << std::endl;
        return;
    }

    y = x;
    int current_color = y->color;
    if (x->left == m_TNULL) {
        z = x->right;
        rbTransplant(x, x->right); // or x->right
    } else if (x->right == m_TNULL) {
        z = x->left;
        rbTransplant(x, x->left); // or  x->left
    } else {
        y = minimum(x->right);
        current_color = y->color;
        z = y->right;
        if (y->parent == x) {
            z->parent = y;
        } else {
            rbTransplant(y, y->right);
            y->right = x->right;
            y->right->parent = y;
        }
        rbTransplant(x, y);
        y->left = x->left;
        y->left->parent = y;
        y->color = x->color;
    }
    delete x;
    if (current_color == BLACK) {
        deleteFix(z);
    }
}

Node* RedBlackTree::minimum(Node* node) {
    while (node->left != m_TNULL) {
        node = node->left;
    } 
    return node;
}


void RedBlackTree::deleteNode(int value) {
    delete_node_helper(m_root, value);
}

RedBlackTree::RedBlackTree() {
    m_TNULL = new Node;
    m_TNULL->color = 0;
    m_TNULL->left = nullptr;
    m_TNULL->right = nullptr;
    m_root = m_TNULL;
}
RedBlackTree::~RedBlackTree() {
    clear();
}
Node* RedBlackTree::search_helper(Node* node, int value) {
    if (node == m_TNULL || node->data == value) {
        return node;
    }
    if (m_root->data > value) {
        return search_helper(node->left, value);
    }
    return search_helper(node->right, value);
}



void RedBlackTree::clear_helper(Node* node) {
    if (node != nullptr && node != m_TNULL) {
        clear_helper(node->left);
        clear_helper(node->right);
        delete node;
    }    
}

void RedBlackTree::clear() {
    clear_helper(m_root);
    m_root = m_TNULL;
}


Node* RedBlackTree::search(int value) {
    return search_helper(m_root, value);
}
void RedBlackTree::insert(int value) {
    Node* node = new Node(value);
    node->right = m_TNULL;
    node->left = m_TNULL;

    Node* x = nullptr;
    Node* y = m_root;

    while (y != m_TNULL) {
        x = y;
        if (node->data > y->data) {
            y = y->right;
        } else {
            y = y->left;
        }
    }
    node->parent = x;
    if (!x) {
        m_root = node;
    } else if (node->data < x->data) {
        x->left = node;
    } else {
        x->right = node;
    }
    if (node->parent == nullptr) {
        node->color = BLACK;
        return;
    }
    if (node->parent->parent == nullptr) {
        return;
    }
   
    insertFix(node);
    
}

void RedBlackTree::inorder(Node* root) {
    if (root != m_TNULL) {
        inorder(root->left);
        std::cout << root->data << std::endl;
        inorder(root->right);
    }
}

void RedBlackTree::print() {
    inorder(m_root);
}