#include <bits/stdc++.h>
using namespace std;

int firstocc(vector<int> arr, int k){
    int s =0;
    int e = arr.size()-1;
    int m= (s+e)/2;
    while(s<e){
        m =(s+e)/2;
        if(arr[m] == k){
            if(arr[m] == arr[m-1]) e =m;
            else{return m;}
        }
        else if(k<arr[m]){
            e=m-1;
        }
        else{s = m+1;}
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,2,9,9,9,9};
    cout<<firstocc(arr, 2);

    return 0;
}