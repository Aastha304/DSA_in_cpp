#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int val;
    node* next;
    node* bottom;
    node(int x) : val(x), next(nullptr), bottom(nullptr) {}
}node;

// how do I sort the lls in one go

node* merge(node* l1, node* l2){
    if(!l1) return l2;
    if(!l2) return l1;
    node* res;

    if(l1->val < l2->val){
        res = l1;
        res->bottom = merge(l1->bottom, l2);
    }
    else{
        res = l2;
        res->bottom = merge(l1, l2->bottom);
    }
    res->next = nullptr;
    return res;
    
}

node* flatten_list(node* head){
    if(!head || !head->next) return head;
    head->next = flatten_list(head->next);
    head = merge(head, head->next);

    return head;

}

void display(node* head){
    node* temp = head;
    while(temp!=nullptr){
        cout<< temp->val<<" ";
        temp = temp->bottom;
    }
    cout<<endl;
}



int main() {
    node* head = new node(5);
    head->bottom = new node(7);
    head->bottom->bottom = new node(8);
    head->bottom->bottom->bottom = new node(30);

    head->next = new node(10);
    head->next->bottom = new node(20);

    head->next->next = new node(19);
    head->next->next->bottom = new node(22);
    head->next->next->bottom->bottom = new node(50);

    head->next->next->next = new node(28);
    head->next->next->next->bottom = new node(35);
    head->next->next->next->bottom->bottom = new node(40);
    head->next->next->next->bottom->bottom->bottom = new node(45);

   node* res = flatten_list(head);
   display(res);
    return 0;
}