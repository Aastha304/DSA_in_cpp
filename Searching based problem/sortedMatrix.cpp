#include <bits/stdc++.h>
using namespace std;

// Find x in sorted matrix - Staircase search O(n)

pair<int, int> sortedMatrix(vector<vector<int>> matrix, int k){
    int n = matrix.size();
    int r =0; int c= n-1;
    while(r<n && c>=0){
        if(matrix[r][c]==k) return {r,c};
        else if(k < matrix[r][c]){
            c--;
        }else{
            r++;
        }
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>> matrix = {
    {10, 20, 30, 40},
    {15, 25, 35, 45},
    {27, 29, 37, 48},
    {32, 33, 39, 50}
    };
    pair<int, int> p = sortedMatrix(matrix, 39);
    cout<< p.first<<" "<< p.second;
  


    return 0;
}