#include<iostream>
using namespace std;

static int stack[UPPERLIMIT];

top = -1;
int addItem(int item){
    top=top+1;
    if(top <UPPERLIMIT){
        stack[top] = item;
    }
    else{
        return;
    }
}