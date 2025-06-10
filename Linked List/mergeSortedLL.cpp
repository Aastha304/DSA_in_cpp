#include <bits/stdc++.h>
using namespace std;

// merge two sorted linked lists

typedef struct node{
    int val;
    struct node* next;
    node(int x): val(x), next(nullptr){}
}node;

node* merge(node* l1, node* l2){
    node dummy(0) ;
    node* tail = &dummy;
    while(l1 && l2){
        if(l1->val < l2->val){
            tail->next  = l1;
            l1 = l1->next;
        }
        else{
            tail->next  = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1? l1:l2;

    return dummy.next;

}

void display(node* head){
    node* temp = head;
    while(temp!=nullptr){
        cout<< temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    node* l1 = new node(1);
    l1->next = new node(3);

    node* l2 = new node(2);
    l2->next = new node(3);

    node* res = merge(l1, l2);
    display(res);

    return 0;
}

