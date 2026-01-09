#include<iostream>
#include<string>
using namespace std;

int main(){
    int stack[20];
    top = -1;
    string postfix[] = {"6", "5", "2", "3", "+", "8", "*", "+", "3", "+", "*"};
    int n = 11;

    for(int i=0; i<n; i++){
        string value = postfix[i];
        if(value!="+"&&value!="-"&& value!="*" && value!="/"){
            stack[++top] = stoi(value);
        }
        else{
            int result;
            int x = stack[top--];
            int y = stack[top--];
            if(value == "+") result = x+y;
            else if(value == "-") result = y-x;
            else if(value == "*") result = y*x;
            else result = y/x;
            stack[++top] = result;
        }
    }
    cout<<"after "<<stack[top];
    return 0;
}