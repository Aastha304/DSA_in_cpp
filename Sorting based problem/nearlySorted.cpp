#include <bits/stdc++.h>
using namespace std;

// O(nlogk)
void kSortedArr(vector<int>& arr,int k ){
    priority_queue<int, vector<int>,greater<int>> minHeap;
    int n= arr.size();
    int index = 0;
    for(int i=0;i<=k;i++){
        minHeap.push(arr[i]);
    }
    for(int i=k+1;i<n;i++){
        arr[index] = minHeap.top();
        minHeap.pop();
        minHeap.push(arr[i]);
        index++;
    }
    while(!minHeap.empty()){
        arr[index++] = minHeap.top();
        minHeap.pop();
    }
}

int main(){
    vector<int> arr= {7,5,3,2,8,10,9};
    kSortedArr(arr,3);
    for(int  i : arr){
        cout<<i<<" ";
    }

    return 0;
}