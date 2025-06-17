#include <bits/stdc++.h>
using namespace std;

vector<int> dupl(vector<int> arr,int n){
    int xorall = 0;
    for(int i =1; i<=n; i++){
        xorall = xorall^i;
    }
    for( int ele: arr){
        xorall = xorall^ele;
    }
    int setbit = xorall & -xorall;
    // xorall = x^y
    int x=0, y =0;
    for(int i: arr){
        if(i & setbit) x = x^i;
        else y= y^i;
    }
    for(int i=1; i<=n;i++){
        if(i & setbit) x= x^i;
        else y = y^i;
    }
    return {x,y};
}

int main(){
    vector<int> arr  = {1,2,3,4,5,2,4};
    vector<int> res = dupl(arr, 5);
    cout<< res[0]<<" "<< res[1];

    return 0;
}