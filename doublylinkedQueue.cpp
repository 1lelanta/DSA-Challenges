#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node*prev;
    Node*next;
};

Node*front = NULL;
Node*rear = NULL;

void enqueue(string y){
    Node*temp = new Node;
    temp->data = y;
    temp->next = NULL;
    temp->prev = NULL;

    if(rear==NULL){
        front = rear = temp;
    }
    else{
        rear->next = temp;
        temp->prev = rear;
        rear = temp;
    }
}

void dequeue(){
    if(front==NULL){
        cout<<"Underflow";
        return;
    }
    Node*temp = front;
    cout<<"deleted: "<<temp->data<<endl;

    front = front->next;

    if(front!=NULL){
        front->prev = NULL;
    }
    else{
        rear = NULL;
    }
    delete temp;
}
void display() {
    Node* temp = front;
    cout << "Queue: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue("A");
    enqueue("B");
    enqueue("C");

    display();

    dequeue();
    dequeue();

    display();

    enqueue("D");

    display();

    dequeue();
    dequeue();
    return 0;
}

