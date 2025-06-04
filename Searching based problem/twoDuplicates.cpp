#include <bits/stdc++.h>
using namespace std;

pair<int, int> byXOR(vector<int> arr, int n){
    int xorN =0;
    for(int i =1 ;i<=n; i++){
        xorN = xorN^i;
    }
    for(int i : arr){
        xorN = xorN^i;
    }
    int setbit = xorN & -xorN ; 
    int x=0,y=0;
    for(int num: arr){
        if(num & setbit) x = x^num;
        else y = y^num;
    }
    for (int i = 1; i <= n; ++i) {
        if (i & setbit)
            x ^= i;
        else
            y ^= i;
    }
    return {x,y};
}

int main(){
    pair<int, int> res = byXOR({1,2,3,4,5,5,3},5);
    cout<< res.first<<" "<<res.second<<endl;

    return 0;
}