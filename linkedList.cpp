#include<iostream>

using namespace std;

struct Node{
	int data;
	Node*next;
};

Node*head = NULL;

void Insert(int value, int n){
	
	Node*temp = new Node();
		temp->data = value;
		temp->next = NULL;
		
		
	if(n==1){
		head= temp;
		return;
	}
	Node*temp2 =  head;
	
	for(int i = 0; i<n-2; i++){
		temp2 = temp2->next;
			}
		temp->next = temp2->next;
		temp2->next = temp;;
	}

void traverse(){
	Node*temp = head;
	
	while(temp !=NULL){
		cout<<temp->data;
		temp = temp->next;
	}
}


int main(){
	
	Insert(20,1);
	Insert(30,2);
	Insert(40,3);
	Insert(50, 4);
	
	traverse();
}