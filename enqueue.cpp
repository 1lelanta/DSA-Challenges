#include<iostream>
#include<string>

using namespace std;

void enqueue(string q[], int &r, int &f,int n,char y){
    if(r==n-1){
        cout<<"overflow"<<endl;
        return;
    }
   if(f==-1){
   	f = 0;
   }
   q[++r] = y;
}
int main(){
    string q[20];
    int r = -1;
    int f= -1;
    int n = 20;
    char y = 'a';
    enqueue(q, r, f, n,y);
    cout<<"first element of queue is: "<<q[f];
}