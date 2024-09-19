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

    void prepend(int data) {
        Node *new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    void insert_after_node(Node *prev_node, int data){
        Node *new_node = new Node(data);
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }

    void delete_node(int key) {
        Node *cur = head;
        if (cur && cur->data == key) {
            head = head->next;
            return;
        }
        Node *prev = head;
        cur = head->next;
        while (cur && cur->data != key) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == nullptr) {
            return; // key is not present in the LinkedList
        }
        prev->next = cur->next;
        return;
    }
};


int main() {
    // let's test the print_list and apped function of our LinkedList
    LinkedList mylist;
    mylist.append(1);
    mylist.append(2);
    mylist.print_list();
    mylist.append(3);
    mylist.prepend(0);
    mylist.print_list();
    mylist.insert_after_node(mylist.head, 9);
    mylist.print_list();
    mylist.delete_node(9);
    mylist.print_list();
    return 0;
}