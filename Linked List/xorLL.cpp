#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int val;
    struct node* npx;
}node;

node* xorfn(node* a, node* b){
    return (node*)((uintptr_t)(a)^(uintptr_t)(b));
}

void insert(node** head, int data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->val = data;

    new_node->npx = xorfn(NULL, *head);

    if(*head!=NULL){
        node* next = xorfn(NULL, (*head)->npx);
        (*head)->npx = xorfn(new_node, next);
    }
    *head = new_node;
}

void printList(node* head) {
    node* curr = head;
    node* prev = NULL;
    node* next;

    while (curr != NULL) {
        printf("%d ", curr->val);
        next = xorfn(prev, curr->npx);
        prev = curr;
        curr = next;
    }
    printf("\n");
}


int main(){
    node* head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    printf("XOR Linked List: ");
    printList(head);


    return 0;
}