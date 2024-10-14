#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val;
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(int value);
    void push_front(int value);
    void insert_after(int value, int position);
    void delete_val(int value);
    void delete_pos(int position);
    void pop_front();
    void pop_back();
    void print();
    void print_reverse();

    ~DoublyLinkedList();
};

#endif // DOUBLYLINKEDLIST_H
