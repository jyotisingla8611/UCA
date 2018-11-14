#include<iostream>
using namespace std;

void toh(int n,char a,char b,char c){
    if(n == 1){
        cout<<"Move 1st disk from "<<a<<" to "<<c<<endl;
        return ;
    }
    toh(n-1,a,c,b);
    cout<<"Move "<< n<<"th disk from "<<a<<" to "<<c<<endl;
    toh(n-1,b,a,c);
    //cout<<"Move
}

int main(){
    toh(3,'a','b','c');
}
