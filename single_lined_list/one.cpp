#include <iostream>

class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node

    // Constructor to initialize the node
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head; // Pointer to the head of the list

public:
    // Constructor to initialize the list
    LinkedList()
    {
        head = nullptr;
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

    // Function to insert a node at the beginning of the list
    void prepend(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode; // Make the new node the head
    }

    // Function to delete a node by value
    void deleteValue(int value)
    {
        if (head == nullptr)
        {
            std::cout << "List is empty. Nothing to delete." << std::endl;
            return;
        }

        // If the head node needs to be deleted
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Find the node to delete
        Node *temp = head;
        while (temp->next != nullptr && temp->next->data != value)
        {
            temp = temp->next;
        }

        // If the node was not found
        if (temp->next == nullptr)
        {
            std::cout << "Value " << value << " not found in the list." << std::endl;
            return;
        }

        // Delete the node
        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Function to display the list
    void display()
    {
        if (head == nullptr)
        {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    // Destructor to free memory when list is destroyed
    ~LinkedList()
    {
        Node *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
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
    list.prepend(5);

    // Display the list
    std::cout << "Linked List: ";
    list.display();

    // Delete a value
    std::cout << "Deleting 20 from the list." << std::endl;
    list.deleteValue(20);
    list.display();

    return 0;
}
