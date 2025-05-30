#include <bits/stdc++.h>
using namespace std;

// using recursion
void rev(queue<int> q){
    if(q.empty()) return;
    int v = q.front();
    q.pop();
    rev(q);
    cout<<v<<" ";
}

// by stack
void reverse(queue<int> q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    cout<<"reversed queue"<<endl;
    while(!s.empty()){
        cout<< s.top()<<" ";
        s.pop();
    } 
}

void display(queue<int> q){
    queue<int> temp = q;
    while(!temp.empty()){
        cout<< temp.front()<<" ";
        temp.pop();
    }
    cout<<endl;
}

int main(){
    queue<int> q;
    q.push(1);q.push(2);q.push(3);
    display(q);
    rev(q);

    return 0;
}