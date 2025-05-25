// Given N sticks, where the length of each stick is a
// positive integer. A cut operation is performed on the
// sticks such that all of them are reduced by the length of
// the smallest stick.
// Given the length of N sticks, print the number of sticks that
// are left before each subsequent cut operations.

#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> sticks){
    int n = sticks.size();
    sort(sticks.begin(), sticks.end());
    int i =0; int count =0;
    while(i<n){
        if(sticks[i]==sticks[i-1]){
            count++;
        }
        else{

            cout<<"total = "<<n-i<<" ,smallest lenght = "<<sticks[i]<<endl;
        }
        i++;
    }
}

int main(){
    vector<int> arr= {3,4,1,1,4,2,2,2,5};
    brute(arr);


    return 0;
}