#include <bits/stdc++.h>
using namespace std;

bool assemble(int n, int p, int k, vector<int> arr){
    //each row - p students
    sort(arr.begin(), arr.end());
    if(n%p==0){
       return true;
    }
    else if(n%p<=k){
        return true;
    }
    return false;
}

int main(){
    cout<< assemble(4,2,1,{150,140,140,180})<<endl;
    cout<< assemble(3,4,1,{120,150,145});
    return 0;
}