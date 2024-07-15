#ifndef TREE_H
#define TREE_H

#include <iostream>

template <typename T>
class Tree {
protected:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& d, Node* l = nullptr, Node* r = nullptr) : data(d), left(l), right(r) {}
    };

    Node* root;

    // Helper functions
    void clear(Node* node);
    void inOrder(Node* node) const;
    int countLeaves(Node* node) const;
    int treeHeight(Node* node) const;
    void reflectTree(Node* node);
    int countOnlyLeftSons(Node* node) const;

public:
    Tree() : root(nullptr) {}
    ~Tree() { 
        clear(root); 
        
    }

    // Core functions
    void add(const T& val);
    void inOrder() const;

    // New methods
    int leaves() const;
    int height() const;
    void reflect();
    int onlyLeftSon() const;
};

template <typename T>
void Tree<T>::add(const T& val) {
    if (!root) {
        root = new typename Tree<T>::Node(val);
    } else {
        typename Tree<T>::Node* current = root;
        typename Tree<T>::Node* parent = nullptr;
        while (current) {
            parent = current;
            if (val < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        if (val < parent->data) {
            parent->left = new typename Tree<T>::Node(val);
        } else {
            parent->right = new typename Tree<T>::Node(val);
        }
    }
}

template <typename T>
void Tree<T>::inOrder() const {
    inOrder(root);
}

template <typename T>
void Tree<T>::inOrder(typename Tree<T>::Node* node) const {
    if (node) {
        inOrder(node->left);
        std::cout << node->data << " ";
        inOrder(node->right);
    }
}

template <typename T>
void Tree<T>::clear(typename Tree<T>::Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template <typename T>
int Tree<T>::countLeaves(typename Tree<T>::Node* node) const {
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    return countLeaves(node->left) + countLeaves(node->right);
}

template <typename T>
int Tree<T>::leaves() const {
    return countLeaves(root);
}

template <typename T>
int Tree<T>::treeHeight(typename Tree<T>::Node* node) const {
    if (!node) return 0;
    return 1 + std::max(treeHeight(node->left), treeHeight(node->right));
}

template <typename T>
int Tree<T>::height() const {
    return treeHeight(root);
}

template <typename T>
void Tree<T>::reflectTree(typename Tree<T>::Node* node) {
    if (node) {
        reflectTree(node->left);
        reflectTree(node->right);
        std::swap(node->left, node->right);
    }
}

template <typename T>
void Tree<T>::reflect() {
    reflectTree(root);
}

template <typename T>
int Tree<T>::countOnlyLeftSons(typename Tree<T>::Node* node) const {
    if (!node) return 0;
    int count = 0;
    if (node->left && !node->right) count++;
    return count + countOnlyLeftSons(node->left) + countOnlyLeftSons(node->right);
}

template <typename T>
int Tree<T>::onlyLeftSon() const {
    return countOnlyLeftSons(root);
}

#endif // TREE_H
