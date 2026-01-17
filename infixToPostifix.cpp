#include<iostream>
#include<string>
#include <cctype>
using namespace std;

int precedence(char op){
	if(op == '(') return 0;
	if(op =='+' || op == '-') return 1;
	if(op=='*'|| op=='/') return 2;
	
	return -1;
}

string infixToPostifix(string infix){
	char stack[100];
	string postifix="";
	int top=-1;
	for(int i=0; i<infix.length(); i++){
	
	
	char item = infix[i];
	if(isalnum(item)){
		postifix+=item;
	}
	else if(item=='('){
		stack[++top] = item;
	}
	else if(item==')'){
		while(top!=-1&&stack[top]!='('){
			postifix+=stack[top--];
		}
		top--;
	}
	else {
		while(top!=-1&&precedence(stack[top])>=precedence(item)){
			postifix +=stack[top--];
		}
		stack[++top]=item;
	}

}
	while(top!=-1){
		postifix+=stack[top--];
	}
	return postifix;
}

