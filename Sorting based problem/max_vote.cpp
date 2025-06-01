#include <bits/stdc++.h>
using namespace std;

// using sorting - O(nlogn)
int voteCount(vector<int> arr){
    sort(arr.begin(),arr.end());
    int winner =arr[0];
    int maxVote =0;
    int i=1; int count =1;
    while(i<arr.size()){
        if(arr[i]==arr[i-1]){
            count++;
        }
        else{
            if(count>maxVote){
                maxVote = count;
                winner =arr[i-1];
                count=1;
            }          
        }
        i++;       
    }
    return winner;
}

// using counting sort - O(n)
int countSort(vector<int> arr){
    int n = arr.size();
    int maxVote =0;
    int winner =0;
    int max_ = INT_MIN;
    for(int i=0;i<n;i++){
        max_ = max(arr[i], max_);
    }
    vector<int> count(max_+1, 0);

    for(int i:arr){
        count[i]++;
    }
    for(int i=0;i<=max_;i++){
        if(count[i]>maxVote){
            maxVote = count[i];
            winner =i;
        }
    }
    return winner;

}

int main(){
    vector<int> arr = {1,1,1,1,1,2,3,4,4,4,4,4,4,3,3,3,5};
    cout<<voteCount(arr)<<endl;
    cout<<countSort(arr)<<endl;

    return 0;
}