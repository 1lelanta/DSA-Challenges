#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* current = NULL; 


void Insert_at_head(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->prev = NULL;
    temp->next = current;

    if(current != NULL)
        current->prev = temp;

    current = temp; 
}


void add_at_end(int data){
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;

    if(current == NULL) {
        temp1->prev = NULL;
        current = temp1;
        return;
    }

    Node* temp = current;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = temp1;
    temp1->prev = temp;
}


void insert_at_any_position(int data, int n){
    if(n == 1 || current == NULL) {
        Insert_at_head(data);
        return;
    }

    Node* temp = current;
    for(int i=0; i<n-2; i++) {
        if(temp->next == NULL) break;
        temp = temp->next;
    }

    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = temp->next;
    temp1->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = temp1;

    temp->next = temp1;
}


void delete_at_front(){
    if(current == NULL) return;

    Node* temp = current;
    current = current->next;
    if(current != NULL)
        current->prev = NULL;

    delete temp;
}


void delete_at_rear(){
    if(current == NULL) return;

    Node* temp = current;
    while(temp->next != NULL)
        temp = temp->next;

    if(temp->prev != NULL)
        temp->prev->next = NULL;
    else
        current = NULL; 

    delete temp;
}


void delete_at_position(int n){
    if(current == NULL) return;

    if(n == 1) {
        delete_at_front();
        return;
    }

    Node* temp = current;
    for(int i=0; i<n-2; i++) {
        if(temp->next == NULL) return;
        temp = temp->next;
    }

    Node* temp1 = temp->next;
    if(temp1 == NULL) return;

    temp->next = temp1->next;
    if(temp1->next != NULL)
        temp1->next->prev = temp;

    delete temp1;
}


void traverse_from_current() {
    Node* temp = current;
    while(temp != NULL && temp->prev != NULL)
        temp = temp->prev;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void traverseForward(){
    Node* temp = current;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Search for an element
void search_specific_element(int data){
    Node* temp = current;
    while(temp != NULL && temp->data != data)
        temp = temp->next;

    if(temp != NULL)
        cout << "Element found: " << temp->data << endl;
    else
        cout << "Element not found\n";
}

// Test program
int main() {
    Insert_at_head(10);
    Insert_at_head(5);
    add_at_end(20);
    insert_at_any_position(15, 3);
    traverse_from_current();  

    delete_at_front();
    traverse_from_current();   

    delete_at_rear();
    traverse_from_current();   

    delete_at_position(2);
    traverse_from_current();  

    search_specific_element(10); 
    search_specific_element(20); 
}
