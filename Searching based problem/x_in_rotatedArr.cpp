#include <bits/stdc++.h>
using namespace std;

int findElement(vector<int> arr, int target) {
    int n = arr.size();
    int s = 0, e = n - 1;

    while (s < e) {
        int m = s + (e - s) / 2;
        if (arr[m] > arr[e]) 
            s = m + 1;
        else 
            e = m;
        
    }

    int pivot = s;  
    s = 0; e = n - 1;

    if(target >= arr[pivot] && target <= arr[n - 1]) {
        s = pivot;
    } 
    else{
        e = pivot - 1;
    }

    while (s <= e){
        int m = s + (e - s) / 2;
        if (arr[m] == target) return m;
        else if (arr[m] < target) s = m + 1;
        else e = m - 1;
    }

    return -1; 
}

int main(){
    vector<int> arr = {5,6,7,1,2,3,4};
    cout<<findElement(arr,2);

    return 0;
}