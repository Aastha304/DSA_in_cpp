#include <bits/stdc++.h>
using namespace std;

typedef struct  node{
    int val;
    node* next;
    node() : val(0), next(nullptr) {}
    node(int x) : val(x) , next(nullptr){}
    node(int x, node * next): val(x), next(next){}
}node;

// Floyd's algo
bool cycle(node* head){
    node* slow = head;
    node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    }
    return false;

}

int main(){
    node* forward;
    node* head = new node(1,nullptr);
    forward = head->next = new node(2);
    forward->next = new node(2,head);

    cout<< cycle(head);

    return 0;
}