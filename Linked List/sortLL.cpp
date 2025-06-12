#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int val;
    node* next;
    node(int x) : val(x), next(nullptr) {}
}node;

node* merge(node* l1, node* l2) {
    node dummy(0);
    node* tail = &dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1) ? l1 : l2;
    return dummy.next;
}

node* getMid(node* head) {
    node* slow = head;
    node* fast = head->next; 
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* sortList(node* head) {
    if (!head || !head->next) return head;

    node* mid = getMid(head);
    node* right = mid->next;
    mid->next = nullptr; 

    node* leftSorted = sortList(head);
    node* rightSorted = sortList(right);

    return merge(leftSorted, rightSorted);
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
    node* head = new node(3);
    head->next = new node(1);
    head->next->next = new node(4);
    head->next->next->next = new node(2);
    node* res = sortList(head);
    display(res);

    return 0;
}