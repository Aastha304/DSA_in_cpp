#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int val;
    node* next;
    node* random;

    node(int val) {
        val = val;
        next = nullptr;
        random = nullptr;
    }
}node;

node* clone(node* head){
    node* curr = head;
    while (curr) {
        node* clone = new node(curr->val);
        clone->next = curr->next;
        curr->next = clone;
        curr = clone->next;
    }

    curr = head;
    while (curr) {
        if (curr->random)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    curr = head;
    node* cloneHead = head->next;
    while (curr) {
        node* clone = curr->next;
        curr->next = clone->next;
        if (clone->next)
            clone->next = clone->next->next;
        curr = curr->next;
    }

    return cloneHead;
}

int main(){

    return 0;
}