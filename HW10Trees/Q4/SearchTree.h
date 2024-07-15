#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include "Tree.h"

//had to change it for this one- tbh I should have used this format for Q1,2,3 as well
template <typename T>
class SearchTree : public Tree<T> {
public:
    typename Tree<T>::Node* removeNode(typename Tree<T>::Node* node, const T& val);
    typename Tree<T>::Node* findMin(typename Tree<T>::Node* node);
    int findLevel(typename Tree<T>::Node* node, const T& val, int level) const;
    bool search(const T& val); 
    typename Tree<T>::Node* searchNode(const T& val, typename Tree<T>::Node* current); 

    void remove(const T& val);
    int level(const T& val) const;
};

template <typename T>
typename Tree<T>::Node* SearchTree<T>::removeNode(typename Tree<T>::Node* node, const T& val) {
    if (!node) {
        return nullptr;
    } else if (val < node->data) {
        node->left = removeNode(node->left, val);
    } else if (val > node->data) {
        node->right = removeNode(node->right, val);
    } else {
        if (!node->left && !node->right) {
            delete node;
            return nullptr;
        } else if (!node->left) {
            typename Tree<T>::Node* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            typename Tree<T>::Node* temp = node->left;
            delete node;
            return temp;
        } else {
            typename Tree<T>::Node* minNode = findMin(node->right);
            node->data = minNode->data;
            node->right = removeNode(node->right, minNode->data);
        }
    }
    return node;
}

template <typename T>
typename Tree<T>::Node* SearchTree<T>::findMin(typename Tree<T>::Node* node) {
    if (!node) {
        return nullptr;
    }
    while (node->left) {
        node = node->left;
    }
    return node;
}

template <typename T>
void SearchTree<T>::remove(const T& val) {
    this->root = removeNode(this->root, val);
}

template <typename T>
int SearchTree<T>::findLevel(typename Tree<T>::Node* node, const T& val, int level) const {
    if (!node) {
        return -1;
    }
    if (val == node->data) {
        return level;
    }
    int downlevel = findLevel(node->left, val, level + 1);
    if (downlevel != -1) {
        return downlevel;
    }
    downlevel = findLevel(node->right, val, level + 1);
    return downlevel;
}

template <typename T>
int SearchTree<T>::level(const T& val) const {
    return findLevel(this->root, val, 0);
}

template<class T>
bool SearchTree<T>::search(const T& val) {
    return searchNode(val, this->root) != nullptr;
}

template<class T>
typename Tree<T>::Node* SearchTree<T>::searchNode(const T& val, typename Tree<T>::Node* current) {
    while (current) {
        if (val == current->data) {
            return current;
        } else if (val < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return nullptr;
}

#endif // SEARCHTREE_H
