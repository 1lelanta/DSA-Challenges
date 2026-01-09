#include<iostream>
using namespace std;

static int stack[UPPERLIMIT];

top = -1;
void addItem(int item){
    top=top+1;
    if(top <UPPERLIMIT){
        stack[top] = item;
    }
    else{
        return;
    }
}

void del_el(){
    int del_val = 0;

    if(top==-1){
        cout<<"stack underflow";
    }
    else{
        del_val = stack[top];
        stack[top] = NULL;
        top-=1;
    }
    return;
}

