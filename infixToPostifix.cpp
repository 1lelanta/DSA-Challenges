#include<iostream>
#include<string>
using namespace std;

int precedence(char op){
    if(op=='(') return 0;
    if(op=="+" || op =="-") return 1;
    if(op=="*"|| op =="/") return 2;

    return -1;
}

string infixToPostifix(string infix){
    char stack[100];
    int top = -1;
    string postfix="";

    for(int i=0; i<infix.length(); i++){
        char item = infix[i];
        if(isalnum(item)){
            postfix+=item
        }
        else if(item=='('){
            stack[++top] = item;
        }
        else if(item ==')'){
            while(top!=-1 && stack[top]!='('){
                postfix += stack[top--];
            }
            top--;
        }
        else{
            while (top!=-1 && precedenc(stack[top]> precedence(item))){
                postfix+= stack[top--]
            }
            stack[++top]= item;

            
        }
    }

    while (top!=-1){
        postfix+=stack[top--];
    }

    return postifix;
}

int main() {
    string infix = "a+b*c+(d*e+f)*g";
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}