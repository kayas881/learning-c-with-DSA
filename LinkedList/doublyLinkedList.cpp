#include <iostream>
using namespace std;

class node{
public:
    int data; // data stored in the node
    node* next; // pointer to the next node
    node* prev; // pointer to the previous node

    // constructor to initialize the node with a given value
    node(int val){
       data = val;
       next = NULL;
       prev = NULL;
    }
};

// function to insert a new node at the head of the linked list
void insertAtHead(node* &head, int val){
    node* n = new node(val); // create a new node with the given value
    n->next = head; // set the next pointer of the new node to the current head
    if(head != NULL) {
       head->prev = n; // set the previous pointer of the current head to the new node
    }
    head = n; // update the head to point to the new node
}

// function to insert a new node at the tail of the linked list
void insertAtTail(node* &head, int val){
    if(head == NULL){
       insertAtHead(head, val); // if the list is empty, insert the node at the head
       return;
    }
    node* n = new node(val); // create a new node with the given value
    node* temp = head;

    while(temp->next != NULL){
       temp = temp->next; // traverse to the last node
    }
    temp->next = n; // set the next pointer of the last node to the new node
    n->prev = temp; // set the previous pointer of the new node to the last node
}

void display(node* head){
    node* temp = head;

    while(temp->next !=NULL){
        cout<<"<-"<<temp->data<<"->";
        temp = temp->next;
    }
   cout<<endl;
}

void deleteAtHead(node* &head){
    node* todelete = head;

    head = head->next;
    head->prev = NULL;

    delete todelete;
}

void deletion(node* &head, int pos){

    if(pos==1){
        deleteAtHead(head);
    }


    node* temp = head;
    int count=1;
    while(temp!=NULL && count!=pos){
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp->next!=NULL){ 
        temp->next->prev = temp->prev;
        }
   
    delete temp;
}
int main(){
    node* head =NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);
    insertAtHead(head,5);
    display(head);
    deletion(head,5);
    display(head);


    return 0;
}