#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* current = NULL; 

void Insert_at_head(int data) {
    if (current == NULL) {
        cout << "List is empty\n";
        return;
    }

    
    Node* head = current;
    while (head->prev != NULL) {
        head = head->prev;
    }

    // Step 2: create new node
    Node* temp = new Node();
    temp->data = data;
    temp->prev = NULL;
    temp->next = head;

    head->prev = temp;


}

void add_at_end(int data){
    if(current ==NULL){
       Node*temp = new Node;
       temp->data = data;
       temp->next = NULL;
       temp->prev = NULL;
       current = temp;
       return;
    }

    Node *temp = current;

    while(temp->next!=NULL){
        temp = temp->next;
    }

    Node*temp1 = new Node;
    temp1->data = data;
    temp1->next = NULL;

    temp1->prev = temp;
    temp->next = temp1;

}

void insert_at_any_position(int data, int n){
    if(current ==NULL|| n ==1){
        Node*temp = new Node;
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;
        current = temp;

        if (current !=NULL){
            
        }
    }

    Node*temp = current;
    for(int i=0; i<n-2; i++){
        temp = temp->next;
    }
    Node *temp1 = new Node;
    temp1->data = data;
    temp1->next = NULL;
    temp1->next = temp->next;
    temp->next = temp1;
    temp1->prev = temp;

    if(temp1->next!=NULL){
        temp1->next->prev = temp1;
    }
}

void traverse_from_current() {
    Node* temp = current;
    while (temp->prev != NULL)
        temp = temp->prev; 

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



int main() {
  
}
