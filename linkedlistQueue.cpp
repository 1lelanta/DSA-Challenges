#include <iostream>
using namespace std;

struct Node {
    string data;
    Node*next;

};

Node*front = NULL;
Node*rear = NULL;


void enqueue(string y){
    Node*temp = new Node;
    temp->data = y;
    temp->next = NULL;

    if(rear ==NULL){
        front = rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
}

void dequeue(){
    if(front == NULL){
        cout<<"underflow";
        return;
    }
        Node*temp = front;
        cout<<"deleleted element: "<<temp->data;
        front = front->next;
        if(front ==NULL){
            rear == NULL;
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
    dequeue(); 

    return 0;
}