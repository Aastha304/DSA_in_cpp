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

int evaluatePostfix(string str){
    stack<int> stk;
    int i=0;
    while(i<str.size()){
        if((str[i]>='0' && str[i]<='9')){
            stk.push((str[i])-'0');
        }
        else{
            if(stk.size()>1){
            int v1 = stk.top();
            stk.pop();
            int v2 = stk.top();
            stk.pop();
            if(str[i]=='*') stk.push(v1*v2);
            if(str[i]=='/') stk.push(v2/v1);
            if(str[i]=='^') stk.push(v2^v1);
            if(str[i]=='+') stk.push(v1+v2);
            if(str[i]=='-') stk.push(v2-v1);
    
            }
        }i++;
    }
    if(!stk.empty()) return stk.top();

}

// helper function for inf_to_postf
int priority(char c){
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

string inf_to_postf(string str){
    string res = "";
    stack<char> stk;

    for(int i = 0; i < str.size(); i++) {
        char c = str[i];

        if(isalnum(c)) {
            res += c;
        }
        else if(c == '(') {
            stk.push(c);
        }
        else if(c == ')') {
            while(!stk.empty() && stk.top() != '(') {
                res += stk.top();
                stk.pop();
            }
            if(!stk.empty()) stk.pop(); // remove '('
        }
        else { // operator
            while(!stk.empty() && priority(c) <= priority(stk.top()) && c != '^') {
                res += stk.top();
                stk.pop();
            }
            stk.push(c);
        }
    }

    while(!stk.empty()) {
        res += stk.top();
        stk.pop();
    }

    return res;
}

int main(){
    // string a = "-*AB/CD";
    // convert(a);
    // string a = "562+*84/-";
    // cout<<evaluatePostfix(a);
    string c ="(A*B)-(C/D)";
    string res = inf_to_postf(c);
    cout<< res;


    return 0;
}