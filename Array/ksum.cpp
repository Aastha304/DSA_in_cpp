#include <bits/stdc++.h>
using namespace std;

int maxksum(vector<int> arr, int k){
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    int maxSum=sum;
    for(int j=k;j<arr.size();j++){
        sum = sum+arr[j]-arr[j-k];
        maxSum = max(maxSum,sum);
    }
    return maxSum;
}

int main(){
    cout<< maxksum({1,2,4,-2,0,1},3);

    return 0;
}