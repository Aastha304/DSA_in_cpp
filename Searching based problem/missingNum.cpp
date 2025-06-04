#include <bits/stdc++.h>
using namespace std;

int countSort(vector<int> arr){
    
    vector<int> count(arr.size()+2, 0);
    count[0] = 1;
    for(int i:arr){
        count[i]++;
    }
    for(int i=0;i<count.size();i++){
        if(count[i]==0) return i;
    }
    return -1;

}

int byXOR(vector<int> arr){
    int n= arr.size()+1;
    int xorN =1;
    for(int i =2;i<=n;i++){
        xorN=xorN^i;
    }
    for(int i: arr){
        xorN = xorN^i;
    }
    return xorN;
}

int usingHash(vector<int> arr){
    unordered_map<int, int> hash;
    for(int i: arr){
        hash[i]++;
    }
    for (int i = 1; i <= arr.size()+1; i++) {
        if (!hash[i]) {
            return i;
        }
    }
    return -1;
    
}

int main(){
    vector<int> arr = {1,2,4,5};
    cout<<byXOR(arr)<<endl;
    cout<<countSort(arr)<<endl;
    cout<< usingHash(arr)<<endl;

    return 0;
}