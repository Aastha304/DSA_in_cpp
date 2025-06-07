#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int val;
    node* next;
    node() : val(0), next(nullptr) {}
    node(int x) : val(x) , next(nullptr){}
    node(int x, node * next): val(x), next(next){}
}node;

node* merge(node*l1, node* l2){
    if (!l1) return l2;
    if (!l2) return l1; 
    if (l2->val < l1->val) swap(l1, l2);
    node* head = l1;

    while (l1 && l2) {
        node* temp = nullptr;
        while (l1 && l1->val <= l2->val) {
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        swap(l1, l2);
    }

    return head;
}

node* mergeKLists(vector<node*>& lists) {
    if (lists.empty()) return nullptr;

    int interval = 1;
    int n = lists.size();

    while (interval < n) {
        for (int i = 0; i + interval < n; i += interval * 2) {
            lists[i] = merge(lists[i], lists[i + interval]);
        }
        interval *= 2;
    }

    return lists[0];
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
    
    node* head1 = new node(7);
    head1 = new node(3,head1);
    head1 = new node(2,head1);
    head1 = new node(1,head1);
    // display(head1);
    node* head2 = new node(10);
    head2 = new node(8,head2);
    head2 = new node(6,head2);
    // display(head2);
    node* head3 = new node(9);
    head3 = new node(5,head3);
    head3 = new node(4,head3);
    vector<node*> lists ={head1, head2, head3};
    node* l1 = mergeKLists( lists);
    display(l1);


    return 0;
}