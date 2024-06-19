#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class List {
protected:
    class Node {
    public:
        int def_key;
        Node* def_next;

        // Constructors
        Node(int key = 0, Node* next = NULL);
        Node(const Node& source);
    };

    Node* def_head;

public:
    // Constructors and destructor
    List();
    List(const List& L);
    ~List();
    List(List&& L) noexcept;

    // List operations
    void clear();
    void add(int value);
    void removeFirst();
    int firstElement() const;
    bool isEmpty() const;
    List::Node* search(const int& value) const;

    // Operator methods
    List& operator=(const List& rhs);
    friend ostream& operator<<(ostream& os, const List& L);
    friend istream& operator>>(istream& is, List& L);
};

#endif // LIST_H
