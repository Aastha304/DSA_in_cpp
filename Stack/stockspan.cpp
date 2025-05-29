#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(vector<int> arr){
    vector<int> span(arr.size(),0);
    int stack[arr.size()];
    int top =-1;
    for(int i=0; i<arr.size();i++){
        while(top>-1 && arr[stack[top]]<=arr[i]){
            top--;
        }
        if(top==-1){
            span[i] = i+1;
        }
        else{
            span[i] = i-stack[top];
        }
        top++;
        stack[top] = i;
    }
    return span;

}

int main(){
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span = stockSpan(arr);
    for(int i: span){
        cout<<i<<" ";
    }

    return 0;
}