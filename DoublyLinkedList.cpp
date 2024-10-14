#include "DoublyLinkedList.h"

// Method to add a value at the end of the list
void DoublyLinkedList::push_back(int value) {
    Node* newNode = new Node(value);
    if (!tail) { // If there's no tail, the list is empty
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Method to add a value at the front of the list
void DoublyLinkedList::push_front(int value) {
    Node* newNode = new Node(value);
    if (!head) { // If there's no head, the list is empty
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Method to insert a node after a specific position
void DoublyLinkedList::insert_after(int value, int position) {
    if (position < 0) {
        cout << "Position must be >= 0." << endl;
        return;
    }
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
        return;
    }
    Node* temp = head;
    for (int i = 0; i < position && temp; ++i)
        temp = temp->next;
    if (!temp) {
        cout << "Position exceeds list size. Node not inserted.\n";
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next)
        temp->next->prev = newNode;
    else
        tail = newNode; // Inserting at the end
    temp->next = newNode;
}

// Method to delete a node by value
void DoublyLinkedList::delete_val(int value) {
    if (!head) return; // Empty list
    Node* temp = head;
    while (temp && temp->data != value)
        temp = temp->next;
    if (!temp) return; // Value not found
    if (temp->prev) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next; // Deleting the head
    }
    if (temp->next) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev; // Deleting the tail
    }
    delete temp;
}

// Method to delete a node by position
void DoublyLinkedList::delete_pos(int position) {
    if (!head || position < 0) return; // Empty list or invalid position
    Node* temp = head;
    for (int i = 0; i < position && temp; ++i)
        temp = temp->next;
    if (!temp) return; // Position exceeds list size
    if (temp->prev) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next; // Deleting the head
    }
    if (temp->next) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev; // Deleting the tail
    }
    delete temp;
}

// Method to pop the front node
void DoublyLinkedList::pop_front() {
    if (!head) return; // Empty list
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr; // Update head's prev pointer
    else tail = nullptr; // List is now empty
    delete temp;
}

// Method to pop the back node
void DoublyLinkedList::pop_back() {
    if (!tail) return; // Empty list
    Node* temp = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr; // Update tail's next pointer
    else head = nullptr; // List is now empty
    delete temp;
}

// Method to print the list forward
void DoublyLinkedList::print() {
    Node* current = head;
    if (!current) return;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Method to print the list backward
void DoublyLinkedList::print_reverse() {
    Node* current = tail;
    if (!current) return;
    while (current) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

// Destructor
DoublyLinkedList::~DoublyLinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
