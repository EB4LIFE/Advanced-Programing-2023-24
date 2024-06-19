#include "List.h"

// Node class constructors
List::Node::Node(int key, Node* next) : def_key(key), def_next(next) {}
List::Node::Node(const Node& source) : def_key(source.def_key), def_next(source.def_next) {}

// List class constructors and destructor
List::List() : def_head(NULL) {}

List::List(const List& L) {
    Node* src, * trg;
    if (L.def_head == NULL) {
        def_head = NULL;
    } else {
        def_head = new Node(L.def_head->def_key, NULL);
        src = L.def_head;
        trg = def_head;

        while (src->def_next != NULL) {
            trg->def_next = new Node(src->def_next->def_key, NULL);
            src = src->def_next;
            trg = trg->def_next;
        }
    }
}

List::~List() {
    clear();
}

List::List(List&& L) noexcept : def_head(L.def_head) {
    L.def_head = NULL;
}

// List operations
void List::clear() {
    Node* q = NULL;
    for (Node* p = def_head; p != NULL; p = q) {
        q = p->def_next;
        delete p;
    }
    def_head = NULL;
}

void List::add(int value) {
    def_head = new Node(value, def_head);
    if (!def_head) {
        throw "failed to allocate memory for new Node";
    }
}

void List::removeFirst() {
    if (def_head != NULL) {
        Node* temp = def_head->def_next;
        delete def_head;
        def_head = temp;
    }
}

int List::firstElement() const {
    if (isEmpty()) {
        throw "the List is empty, no first Element";
    }
    return def_head->def_key;
}

bool List::isEmpty() const {
    return (def_head == NULL);
}

List::Node* List::search(const int& value) const {
    Node* p = def_head;
    while ((p != NULL) && (p->def_key != value)) {
        p = p->def_next;
    }
    return p;
}

// Operator methods
List& List::operator=(const List& rhs) {
    if (this == &rhs) {
        return *this;
    }
    if (!isEmpty()) {
        clear();
    }

    Node* src, * trg;
    if (rhs.def_head == NULL) {
        def_head = NULL;
    } else {
        def_head = new Node(rhs.def_head->def_key, NULL);
        src = rhs.def_head;
        trg = def_head;

        while (src->def_next != NULL) {
            trg->def_next = new Node(src->def_next->def_key, NULL);
            src = src->def_next;
            trg = trg->def_next;
        }
    }

    return *this;
}

ostream& operator<<(ostream& os, const List& L) {
    List::Node* p = L.def_head;
    while (p != NULL) {
        os << p->def_key << " ";
        p = p->def_next;
    }
    return os;
}

istream& operator>>(istream& is, List& L) {
    if (L.def_head != NULL) {
        L.clear();
    }
    int temp;
    is >> temp;

    L.add(temp);
    List::Node* p = L.def_head;
    is >> temp;

    while (temp < p->def_key) {
        p->def_next = new List::Node(temp, NULL);
        p = p->def_next;
        is >> temp;
    }

    return is;
}
