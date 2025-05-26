#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> arr, int k){
    sort(arr.begin(), arr.end());
    return arr[k-1];
}

int kth(vector<int> arr, int k){
    priority_queue<int, vector<int>,greater<int>> pq;
    for(int i=0;i<arr.size();i++){
        pq.push(arr[i]);
    }
    for(int i=0;i<arr.size()-k;k++){pq.pop();}
    return pq.top();

}

int main(){
    vector<int> arr = {1,2,-3,4,5};
    cout<<kth(arr,3);
 
    return 0;
}