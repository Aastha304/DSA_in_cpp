#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int val;
    struct node* next;
    node(int x): val(x), next(nullptr){}
    // node(int x, node* next): val(x) , next()
}node;

// order = LSD to MSD
node* sum2LL(node* l1, node* l2) {
    node dummy(0);
    node* tail = &dummy;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        tail->next = new node(sum % 10);
        tail = tail->next;
        carry = sum / 10;
    }

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
    node* h1 = new node(3);
    h1->next = new node(4);
    // 3->4
    node* h2 = new node(9);
    h2->next = new node(8);
    h2->next->next = new node(7);
    // 9->8->7
    node * res = sum2LL(h1, h2);
    display(res); //2->3->8

    return 0;
}