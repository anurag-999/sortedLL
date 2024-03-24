#include <iostream>

using namespace std;

// Define a node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    // Constructor
    Node(int val) : data(val), next(nullptr) {}
};

class SortedLinkedList {
private:
    Node* head;

public:
    // Constructor
    SortedLinkedList() : head(nullptr) {}

    // Destructor
    ~SortedLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Function to insert a new element into the sorted linked list
    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr || head->data >= val) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->data < val) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to display the elements of the sorted linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    SortedLinkedList list;

    // Insert elements into the sorted linked lists
    list.insert(5);
    list.insert(10);
    list.insert(2);
    list.insert(7);
    list.insert(1);

    // Display the sorted linked list
    cout << "Sorted Linked List: ";
    list.display();

    return 0;
}
