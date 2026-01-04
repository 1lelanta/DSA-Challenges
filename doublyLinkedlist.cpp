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
        cout<<"list is empty";
    }

    Node *temp = current;

    while(temp->next!=NULL){
        temp = temp->next;
    }

    Node*temp1 = new Node;
    temp->data = data;
    temp->next = NULL;
    
    temp->prev = temp1;
    temp1->next = temp;

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
