#include <bits/stdc++.h>

using namespace std;

int sumpower(int n,int k, string str){  
    int power =0;
    for(int i=0;i<n-1;i++){
        if(str[i]!=str[i+1]){
            int minInd = max(0,i-k+1);
            int maxInd = min(n-k-1,i);
            if(maxInd>=minInd){
                power+= maxInd - minInd+1;
            }
        }
    }
    return power;

}

int main(){
    cout<< sumpower(6,3,"aabbcc");

    return 0;
}