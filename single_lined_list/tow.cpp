#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList() {
        head = nullptr;
    };

    // Function to display the list
    void display()
    {
        if (head == nullptr)
        {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node *temp = head;
        while (temp != nullptr) {
            cout << (*temp).data << " -> ";
            temp = (*temp).next;
        }
        cout << "null";
    }

    // Function to insert a node at the end of the list
    void append(int value)
    {
        Node *newNode = new Node(value); // Create a new node
        if (head == nullptr)
        {
            head = newNode; // If list is empty, new node becomes the head
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next; // Traverse to the last node
            }
            temp->next = newNode; // Link the last node to the new node
        }
    }
};

int main()
{
    LinkedList list;

    // Insert elements into the list
    list.append(10);
    list.append(20);
    list.append(30);

    // Display the list
    std::cout << "Linked List: ";
    list.display();

    Node *one = new Node(10);
    cout << endl;
    cout << (*one).data << endl;
    cout << one->data << endl;

    return 0;
}
