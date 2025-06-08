#include <bits/stdc++.h>
using namespace std;

// Given two arrays each containing n sorted elements. Find median of 2n elements

double findMedian(vector<int>& arr1, vector<int>& arr2){
    int n = arr1.size();
    int s=0, e =n;
    while(s<=e){
        int m = (s+e)/2;
        int j = n -m;

        int left1 = (m ==0)? INT_MIN: arr1[m-1];
        int right1 = (m==n)? INT_MAX: arr1[m];
        int left2 = (j == 0) ? INT_MIN : arr2[j - 1];
        int right2 = (j == n) ? INT_MAX : arr2[j];

        if( left1 <= right2 && left2<= right1){
            return (max(left1, left2) + min(right1 , right2))/2.0;
        }
        else if(left1>right2){
            e = m-1;
        }
        else{
            s = m+1;
        }
    }
    return -1;

}

int main(){
    vector<int> a1 = {1,3,5};
    vector<int> a2 = {2,4,6};
    double r = findMedian(a1,a2);
    cout<< r;

    return 0;
}