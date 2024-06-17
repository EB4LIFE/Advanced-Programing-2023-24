#include "RoundList.h"

void RoundList::addToEnd(int val) {
    if (isEmpty()) {
        add(val);
        def_head->def_next = def_head;
        return;
    }

    Node* p = def_head;
    while (p->def_next != def_head) {
        p = p->def_next;
    }
    p->def_next = new Node(val, def_head);
}

int RoundList::search(int n) const {
    if (isEmpty()) {
        return -1;
    }

    Node* p = def_head;
    for (int i = 0; i < n; i++) {
        p = p->def_next;
    }
    return p->def_key;
}

void RoundList::add(int value) {
    if (isEmpty()) {
        def_head = new Node(value, def_head);
        def_head->def_next = def_head;
    } else {
        Node* p = def_head;
        while (p->def_next != def_head) {
            p = p->def_next;
        }
        p->def_next = new Node(value, def_head);
        def_head = p->def_next;
    }
}

void RoundList::removeFirst() {
    if (isEmpty()) {
        return;
    }
    if (def_head->def_next == def_head) {
        delete def_head;
        def_head = NULL;
    } else {
        Node* temp = def_head;
        Node* p = def_head;
        while (p->def_next != def_head) {
            p = p->def_next;
        }
        def_head = def_head->def_next;
        p->def_next = def_head;
        delete temp;
    }
}
