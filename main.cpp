#include <iostream>
#include <cstdlib>
#include "DoublyLinkedList.h"
using namespace std;

int main() {
    DoublyLinkedList list;

    // Populate the list with random values
    for (int i = 0; i < 10; ++i) {
        list.push_back(rand() % 90 + 10); // Random values between 10 and 99
    }

    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    // Test popping the front
    cout << "Popping front...\n";
    list.pop_front();
    list.print();

    // Test popping the back
    cout << "Popping back...\n";
    list.pop_back();
    list.print();

    // Test deleting a node by position
    cout << "Deleting node at position 3...\n";
    list.delete_pos(3);
    list.print();

    // Test deleting a node by value
    cout << "Deleting node with value 50...\n";
    list.delete_val(50);
    list.print();

    // Clean up
    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}
