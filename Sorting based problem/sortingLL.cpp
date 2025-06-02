#include <bits/stdc++.h>
using namespace std;

typedef struct  node{
   int data;
   node* next;
   node(int val): data(val), next(nullptr){}
}node;

// using insertion sort - O(n^2)
void insert(node*& res, node* newnode){
    if(!res || newnode->data<=res->data){
        newnode->next = res;
        res = newnode;
    }
    else{
        node * curr = res;
        while(curr->next && curr->next->data<newnode->data){
            curr = curr->next;
        }
        newnode->next = curr->next;
        curr->next = newnode;
    }
}
node* insertSort(node* head){
    node* res = nullptr;
    node* curr = head;
    while(curr){
        node* next = curr->next;
        curr->next = nullptr;
        insert(res, curr);
        curr = next;
    }
    return res;
}

// using mergeSort
node* merge(node* l1, node* l2) {
    node temp(0);
    node* tail = &temp;

    while (l1 && l2) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return temp.next;
}

node* mid(node* head) {
    node* slow = head;
    node* fast = head;
    node* prev = nullptr;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev) prev->next = nullptr;
    return slow;
}

node* mergeSort(node* head) {
    if (!head || !head->next) return head;

    node* m = mid(head);
    node* left = mergeSort(head);
    node* right = mergeSort(m);

    return merge(left, right);
}

void printList(node* head) {
    node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    node* head = new node(4);
    head->next = new node(6);
    head->next->next = new node(1);
    printList(head);
    head = mergeSort(head);
    // head = insertSort(head);
    printList(head);

    return 0;
}