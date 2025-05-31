#include <bits/stdc++.h>
using namespace std;


void convert(string prefix){
    stack<string> stk;
    int i=prefix.size()-1;
    while(i>=0){
        if((prefix[i]>='A' && prefix[i]<='Z') || (prefix[i]>='0' && prefix[i]<='9')) {
            stk.push(string(1,prefix[i]));
        }
        else{
            if(stk.size()>1){
            string v1 = stk.top();
            stk.pop();
            string v2 = stk.top();
            stk.pop();
            stk.push("("+v1+prefix[i]+v2+")");
            }
        }
        i--;
    }
    if(!stk.empty())
    cout<<stk.top()<<endl;
}

int main(){
    string a = "-*AB/CD";
    convert(a);

    return 0;
}