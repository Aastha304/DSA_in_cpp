#include <bits/stdc++.h>
using namespace std;

bool duplicates(vector<int> arr){
    unordered_map<int, bool> hash;
    for(int i=0; i<arr.size();i++){
        if(hash[arr[i]]) return true;
        hash[arr[i]] = true;
    }
    return false;
}

void countDuplicates(vector<int> arr){
    unordered_map<int ,int> freq;
    for(int num: arr){
        freq[num]++;
    }
    bool hasdupli = false;
    for(auto& pair: freq){
        cout<< pair.first<< "-> "<<pair.second<<endl;
        if(pair.second>1){
            hasdupli = true;
        }
    }
}

int main(){
    vector<int> arr= {12,11,40,12,5,6,5,12,11};
    cout<<"duplicates found : "<<duplicates(arr);
    countDuplicates(arr);

    return 0;
}