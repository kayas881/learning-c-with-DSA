#include <iostream>
using namespace std;

// Node class to represent each element in the linked list
class node{
public:
    int data;
    node* next;

    // Constructor to initialize the node with a value
    node(int value){
       data = value;
       next = NULL;
    }
};
void insertAtHead(node* &head, int val){
 node* n = new node(val); // Create a new node with the given value
 n->next=head;
 head=n;
 }
// Function to insert a new node at the end of the linked list
void insertAtTail(node* &head, int val){
    node* n = new node(val); // Create a new node with the given value
    if(head == NULL){
       head = n; // If the linked list is empty, make the new node as the head
       return;
    }
    node* temp = head;
    while(temp->next != NULL){
       temp = temp->next; // Traverse to the last node of the linked list
    }
    temp->next = n; // Connect the new node to the last node
}

// Function to display the elements of the linked list
void display(node* head){
    node* temp = head;
    while(temp != NULL){
       cout << temp->data << "->"; // Print the data of each node
       temp = temp->next; // Move to the next node
    }
    cout << endl;
}
// Function to search for a key in the linked list
bool search(node* head, int key){
    node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            return true; // If key is found, return true
        }
        temp = temp->next; // Move to the next node
    }
    return false; // If key is not found, return false
}
// Function to delete the head node of the linked list
void deleteAtHead(node* &head){
    if(head == NULL){
        return; // If the linked list is empty, return
    }
    node* toDelete = head; // Store the head node to be deleted
    head = head->next; // Move the head pointer to the next node
    delete toDelete; // Delete the head node
}
// Function to delete a node with a given value from the linked list
void deletion(node* &head, int val){
    node* temp = head;
    while(temp->next != NULL && temp->next->data != val){
        temp = temp->next; // Traverse to the node before the node to be deleted
    }
    if(temp->next == NULL){
        return; // If the node to be deleted is not found, return
    }
    node* toDelete = temp->next; // Store the node to be deleted
    temp->next = temp->next->next; // Connect the previous node to the next node
    delete toDelete; // Delete the node
}

// Function to reverse the linked list
node* reverse(node* &head) {
    node* prevptr = NULL;     // Initialize previous pointer to NULL
    node* currptr = head;     // Initialize current pointer to the head of the list
    node* nextptr;            // Declare a pointer to keep track of the next node

    while (currptr != NULL) {
        nextptr = currptr->next;    // Store the next node
        currptr->next = prevptr;    // Reverse the current node's pointer
        prevptr = currptr;          // Move the previous pointer forward
        currptr = nextptr;          // Move the current pointer forward
    }

    head = prevptr;  // Update the head to the new head of the reversed list
    return prevptr;  // Return the new head of the reversed list
}
// Function to reverse the linked list recursively
node* reverseRecursive(node* &head){

    // Base case: if the list is empty or has only one node, return the head
    if(head == NULL || head->next == NULL){
        return head;
    }

    // Reverse the rest of the list recursively
    node* newhead = reverseRecursive(head->next);

    // Reverse the current node
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

// Function to reverse every k nodes in the linked list
node* reversek(node* &head, int k){
    node* prevptr = NULL;     // Initialize previous pointer to NULL
    node* currptr = head;     // Initialize current pointer to the head of the list
    node* nextptr;            // Declare a pointer to keep track of the next node

    int count = 0;            // Initialize a counter to keep track of the number of nodes reversed
    while(currptr != NULL && count < k){
        nextptr = currptr->next;    // Store the next node
        currptr->next = prevptr;    // Reverse the current node's pointer
        prevptr = currptr;          // Move the previous pointer forward
        currptr = nextptr;          // Move the current pointer forward
        count++;                    // Increment the counter
    }
    
    if(nextptr != NULL){
        head->next = reversek(nextptr, k);    // Recursively reverse the next k nodes and update the head pointer
    }
    
    return prevptr;  // Return the new head of the reversed list
}
bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow){
            return true;
        }
    }
    return false;
}

// Function to create a cycle in the linked list
void makeCycle(node* &head, int pos){
    node* temp = head;
    node* startNode;

    int count = 1;
    while(temp->next != NULL){
        if(count == pos){
            startNode = temp; // Store the node where the cycle starts
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode; // Connect the last node to the start node to create a cycle
}
// Function to remove the cycle in the linked list, if present
void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;

    // Find the meeting point of the slow and fast pointers
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;

    // Move both pointers at the same pace until they meet again
    while (slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL; // Set the next pointer of the last node in the cycle to NULL to remove the cycle
}

int length(node *head){
    int l=0;
    node* temp = head;
    while(temp != NULL){
        l++;
        temp= temp->next;
    }

    return l;
}

// Function to find the intersection point of two linked lists
int intersection(node* &head1, node* &head2){
    int l1 = length(head1); // Calculate the length of the first linked list
    int l2 = length(head2); // Calculate the length of the second linked list

    int d = 0; // Variable to store the difference in lengths
    node* ptr1; // Pointer to traverse the longer linked list
    node* ptr2; // Pointer to traverse the shorter linked list

    // Determine the longer and shorter linked lists
    if(l1 > l2){
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    // Traverse the longer linked list until the difference in lengths is eliminated
    while(d){
        ptr1 = ptr1->next;
        if(ptr1 == NULL){
            return -1; // If the end of the longer linked list is reached before eliminating the difference, return -1
        }
        d--;
    }

    // Traverse both linked lists in parallel until the intersection point is found
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1 == ptr2){
            return ptr1->data; // If the nodes are the same, it means an intersection point is found
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1; // If no intersection point is found, return -1
}

// Function to create an intersection between two linked lists
void intersect(node* &head1, node* &head2, int pos)
{
    node* temp1 = head1;
    pos--;

    // Traverse to the node at the given position in the first linked list
    while (pos--)
    {
        temp1 = temp1->next;
    }

    node* temp2 = head2;

    // Traverse to the last node of the second linked list
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    // Connect the last node of the second linked list to the node at the given position in the first linked list
    temp2->next = temp1;
}
// Function to append the last k nodes to the beginning of the linked list
node* kappend(node* &head, int k){
    node* newHead;
    node* newTail;
    node* tail = head;
    int l = length(head);
    k = k % l;
    int count = 1;
    
    // Traverse to the node before the kth node from the end
    while(tail->next != NULL){
        if(count == l - k){
            newTail = tail;
        }
        if(count == l - k + 1){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    
    newTail->next = NULL; // Disconnect the new tail from the rest of the list
    tail->next = head; // Connect the original head to the original tail
    return newHead; // Return the new head of the modified list
}
// Purpose: Merge two sorted linked lists iteratively into a single sorted linked list.
/*
1.Initialization: Create a dummy node to simplify the merging process and a pointer p3 to build the new list.
2.Merging:
Compare nodes from head1 and head2, and attach the smaller node to the merged list.
Move to the next node in the list from which the node was taken.
3.Attach Remaining Nodes: Once one list is exhausted, attach the remaining nodes of the other list.
4.Return: Skip the dummy node and return the head of the merged list.

*/
node* merge(node* &head1, node* &head2) {
    node* p1 = head1;
    node* p2 = head2;
    node* dummyNode = new node(-1); // Dummy node to simplify handling head of the merged list
    node* p3 = dummyNode; // Pointer for constructing the merged list

    while (p1 != NULL && p2 != NULL) {
        if (p1->data < p2->data) {
            p3->next = p1;
            p1 = p1->next;
        } else {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next; // Move the pointer forward
    }

    // Attach the remaining nodes
    if (p1 != NULL) {
        p3->next = p1;
    } else {
        p3->next = p2;
    }

    node* result = dummyNode->next; // Skip dummy node
    delete dummyNode; // Clean up
    return result;
}

//Purpose: Merge two sorted linked lists recursively into a single sorted linked list.

/*
1.Base Cases:
If head1 is NULL, return head2 (only head2 remains).
If head2 is NULL, return head1 (only head1 remains).
2.Recursive Merging:
Compare the data of the nodes from head1 and head2.
Recursively merge the rest of the lists.
Attach the smaller node to the result and set its next to the result of the recursive call.
3.Return: Return the head of the merged list.
*/

node* mergeRecursive(node* &head1, node* &head2 ){

    if(head1==NULL){
        return head2;
    }

      if(head2==NULL){
        return head1;
    }

    node* result;
    if(head1->data<head2->data){
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else{
        result = head2;
        result->next=mergeRecursive(head1, head2->next);
    }
    return result;
}


// purpose: evenAfterOdd function to rearrange the linked list such that all even nodes come after all odd nodes.
/*
1. Initialization: Initialize pointers odd and even to the head and the next node of the head, respectively. Also, store the starting node of the even list.
2. Rearrangement:
Traverse the linked list until the end of either the odd or even list is reached.
Connect the odd node to the next odd node and move the odd pointer forward.
Connect the even node to the next even node and move the even pointer forward.
3. Connect the Lists: Connect the last odd node to the starting node of the even list.
4. Termination: If the last node of the odd list is not NULL, set the next of the last even node to NULL.
*/
void evenAfterOdd(node* &head){


    node* odd =head;
    node* even = head->next;
    node* evenStart = even;

    while(odd->next !=NULL && even->next !=NULL){
        odd->next = even->next;
        odd=odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenStart;
    if(odd->next!=NULL){
        even->next =NULL;
    }
}

int main(){
   node* head = NULL;
   int arr[] = {1,2,3,4,5,6};
   for(int i=0;i<6;i++){
    insertAtTail(head,arr[i]);
   }
   display(head);
   evenAfterOdd(head);
   display(head);
  
    // node* newHead = kappend(head,3);
    // display(newHead);
        return 0;
}