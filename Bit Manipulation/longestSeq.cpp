#include <bits/stdc++.h>
using namespace std;

int longestSeqOfOnes(int n){
    if(n==0) return 1;
    bool flipped = false;
    int maxSeq = 0;
    int count =0;
    while(n>0){
        if(n&1) {count++;  maxSeq = max(count, maxSeq);}       
        else if(!flipped){
            flipped = true;
            count++;
            maxSeq = max(count, maxSeq); 

        } 
        else{
            flipped = false;
            count =0;
        }
        n = n>>1;    
    }
    return maxSeq;
}

int main(){
    int n = 1775;
    cout<< longestSeqOfOnes(n);


    return 0;
}