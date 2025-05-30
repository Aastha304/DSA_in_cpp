#include <bits/stdc++.h>
using namespace std;
// queue using stack

// 1 2 3 4 5
// 1 2 3 4 

stack<int> s1;
stack<int> s2;

void enq(int v){
    s1.push(v);
}
int deq(){
    if(s1.empty() && s2.empty()){
        // queue empty
        return -1;
    }
    while(!s1.empty()){     
        s2.push(s1.top());
        s1.pop();
    }
    int v = s2.top();
    s2.pop();
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    return v;
}

void display(){
    stack<int> temp = s1;
    while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;
}

int main(){
    enq(1);
    enq(2);
    enq(3);
    display();
    deq();
    display();

    return 0;
}