#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = nullptr;
    };
};

class LinkedList {
public:
    Node *head;
    LinkedList() {
        head = nullptr;
    }
    void print_list() {
        Node *cur = head;
        while (cur) {
            cout << (*cur).data << " -> ";
            cur = (*cur).next;
        }
        cout << "nullptr" << endl;
    }

    void append(int data) {
        Node *new_node = new Node(data);
        // handle case:1 when head of Linked list is nullptr
        if (!head) {
            head = new_node;
            return;
        }
        // other case
        Node *cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = new_node;
    }
};


int main() {
    // let's test the print_list and apped function of our LinkedList
    LinkedList mylist;
    mylist.append(1);
    mylist.append(2);
    mylist.print_list();
    mylist.append(3);
    mylist.print_list();

    return 0;
}