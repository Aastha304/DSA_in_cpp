// Find sum of contiguous sub-array which has largest sum

#include <bits/stdc++.h>
using namespace std;

// Brute - O(n*n)
int brute(vector<int> arr){
    int maxSum=INT_MIN;
    for(int i=0;i<arr.size()-1;i++){
        int sum=0;
        for(int j=i;j<arr.size();j++){
            sum+=arr[j];
            if(sum>maxSum){maxSum=sum;}
        }
    }
    return maxSum;
}

// Efficient - O(n)
int kadanes(vector<int> arr){
    int sumUpto = 0;
    int maxSum = INT_MIN;
    for(int i=0;i<arr.size();i++){
        sumUpto = (arr[i]+sumUpto)>arr[i]?(arr[i]+sumUpto):arr[i];
        if(sumUpto>maxSum){ maxSum = sumUpto;}
    }
    return maxSum;
}

int main(){
    vector<int> arr = {-2,-4};  //-2
    int res = kadanes(arr);
    cout<< res<<endl;
    res = brute({0,-1,-2}); //6
    cout<<res;
    
    return 0;
}