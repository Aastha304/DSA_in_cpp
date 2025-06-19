#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int ,int> freq;
        for(int i: nums){
            freq[i]++;
        }
        vector<vector<int>> bucket(n+1);
        vector<int> res;

        for(auto& e : freq){
            bucket[e.second].push_back(e.first);
        }

        for(int i = n; i>=0 ; i--){
            for(int f: bucket[i]){
                res.push_back(f);
            }
            if(res.size()>=k) break;
        } 
        return res;      

}

int main(){
    // fn( {1},1 ) = 1
    vector<int> arr = {1,1,1,2,2,3};
    vector<int> res = topKFrequent(arr,2);

    for(int i: res){
        cout<< i<<" ";
    }

    return  0;
}