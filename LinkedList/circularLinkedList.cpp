#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

// Class to define a node in a circular linked list
class node {
public:
    int data;      // Data value of the node
    node* next;    // Pointer to the next node

    // Constructor to initialize the node with a value
    node(int value) {
        data = value;
        next = NULL;
    }
};

// Function to insert a new node with value `val` at the head of the list
void insertAtHead(node* &head, int val) {
    node* n = new node(val);  // Create a new node with the given value

    if (head == NULL) {  // If the list is empty
        n->next = n;     // Point the new node to itself
        head = n;        // Set head to the new node
        return;
    }

    node* temp = head;  // Start from the head of the list

    // Traverse the list to find the last node
    while (temp->next != head) {
        temp = temp->next;
    }

    // Insert the new node at the beginning
    temp->next = n;   // The last node points to the new node
    n->next = head;   // New node points to the old head
    head = n;         // Update the head to the new node
}

// Function to display the circular linked list
void display(node* head) {
    if (head == NULL) {  // Check if the list is empty
        cout << "List is empty" << endl;
        return;
    }

    node* temp = head;  // Start from the head of the list

    // Traverse the list and print each node's data
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);  // Stop when we come back to the head

    cout << endl;
}

// Function to insert a new node with value `val` at the tail of the list
void insertAtTail(node* &head, int val) {
    if (head == NULL) {  // If the list is empty
        insertAtHead(head, val);  // Insert at the head (same as tail in an empty list)
        return;
    }

    node* n = new node(val);  // Create a new node with the given value

    node* temp = head;  // Start from the head of the list

    // Traverse the list to find the last node
    while (temp->next != head) {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = n;   // The last node now points to the new node
    n->next = head;   // New node points to the head, maintaining circular link
}


int main(){

    node* head =NULL;

    int arr[] = {1,2,3,4};
    for(int i=0; i<4; i++){
        insertAtTail(head,arr[i]);
    }

    display(head);
    insertAtHead(head,5);
    display(head);

    return 0;

}