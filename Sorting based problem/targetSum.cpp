#include <bits/stdc++.h>
using namespace std;

// sort arr1,apply binary search for (k-x)for each element x of arr2
pair<int, int> findSum(vector<int> arr1, vector<int> arr2, int k) {
    sort(arr1.begin(), arr1.end());

    for (int i : arr2) {
        int target = k - i;
        int s = 0, e = arr1.size() - 1;

        while (s <= e) {
            int mid = (s + e) / 2;
            if (arr1[mid] == target) return {i, arr1[mid]};
            else if (arr1[mid] > target) e = mid - 1;
            else s = mid + 1;
        }
    }

    return {-1, -1}; 
}

int main(){
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {10,20,30,40};
    pair<int,int> p =findSum(arr1,arr2,25);
    cout<<p.first<<" "<<p.second;

    return 0;
}