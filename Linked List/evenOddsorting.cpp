#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int val;
    node* next;
    node(int x) : val(x), next(nullptr) {}
}node;

void separateOddEven(node*& head){
    if (!head || !head->next) return;

    node *evenStart = nullptr, *evenEnd = nullptr;
    node *oddStart = nullptr, *oddEnd = nullptr;
    node* curr = head;

    while (curr) {
        int val = curr->val;
        if (val % 2 == 0) {
            if (!evenStart) {
                evenStart = curr;
                evenEnd = evenStart;
            } else {
                evenEnd->next = curr;
                evenEnd = evenEnd->next;
            }
        } else {
            if (!oddStart) {
                oddStart = curr;
                oddEnd = oddStart;
            } else {
                oddEnd->next = curr;
                oddEnd = oddEnd->next;
            }
        }
        curr = curr->next;
    }

    if (!evenStart || !oddStart) return;

    evenEnd->next = oddStart;
    oddEnd->next = nullptr;
    head = evenStart;
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
    separateOddEven(head);
    display(head);

    return 0;
}