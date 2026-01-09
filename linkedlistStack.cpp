#include<iostream>
using namespace std;


struct  Node{
    int data;
    Node*next;
}

Node*stack  = NULL;
Node*top = stack;

void push(int item){
    Node*newNode = new Node();
    newNode->data = item;
    newNode->next = NULL;
    if(stack == NULL){
       stack = newNode;
       top = stack;
    }
    else{
        top->next = newNode;
        top = newNode;
    }
}
