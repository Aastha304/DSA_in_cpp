#include <bits/stdc++.h>
using namespace std;

// stack using queue
queue<int> q1;
queue<int> q2;

void in(int v){
    q2.push(v);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();       
    }
    swap(q1,q2);
}

int del(){
    if(q1.empty() && q2.empty()) return -1;
    int v= q1.front();
    q1.pop();
    return v;
}

void display(){
    queue<int> q = q1;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    in(1);
    in(2);
    in(3);
    display(); //1 2 3
    del();
    display(); //2 3
    in(4);
    display(); //2 3 4

    return 0;
}