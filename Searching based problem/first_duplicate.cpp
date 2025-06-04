#include <bits/stdc++.h>
using namespace std;


// works for negative nums bz :
// when you use an unordered_map<int, bool> isfound, accessing a key that doesn’t exist using the subscript operator (isfound[key]) will:
// - Insert the key into the map.
// - Initialize its value using the default constructor of the value type.

int firstDuplicate(vector<int> arr){

    unordered_map<int, bool> isfound;
    for(int num : arr){
        if(!isfound[num]) isfound[num]= true;
        else return num;
    }
    return -1;
}

int main(){
    vector<int> arr= {1,-2,-2,3,3,3};
    cout<< firstDuplicate(arr);


    return 0;
}