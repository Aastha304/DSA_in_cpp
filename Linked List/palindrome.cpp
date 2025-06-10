#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int val;
    struct node* next;
    node(): val(0) , next(nullptr){}
    node(int x): val(x) , next(nullptr){}
    node(int x, node* next): val(x), next(next){} 
}node;

node* create(int n){
    node* head = nullptr;

    for(int i=0;i<n;i++){
        int v;
        cout<< "value: ";
        cin>>v;
        node* temp = new node(v, head);
        head = temp;
    }
    return head;

}
void display(node* head){
    node* temp = head;
    while(temp!=nullptr){
        cout<< temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

// 1 2 3 3 2 1
// 1 2 3 1 2 3

bool isPalindrome(node* head){
    // reverse the second half
    node* slow = head, *fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    node* curr = slow->next;node*prev= nullptr;
    while(curr){
        node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    node * secHalf = prev;
    while(secHalf){
        if(head->val != secHalf->val) return false;
        head = head->next;
        secHalf = secHalf->next;
    }

    return true;
}

int main(){
    node* head = create(5);
    bool res = isPalindrome(head);
    cout<<(res);
    
    return 0;
}