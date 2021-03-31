#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    Node* mergesorted(Node*a ,Node* b)
    { 
        if(a==NULL)
        return b;
        if(b==NULL)
        return a;
     if(a->data<=b->data)
     {
         a->next=mergesorted(a->next ,b);
         return a;
     }
     else
     {
         b->next=mergesorted(a ,b->next);
         return b;
     }
    }
    Node* midnode(Node* head)
    {
        Node* slow=head;
        Node* fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    
    }
    
    Node* mergeSort(Node* head) {
        if(head==NULL || head->next==NULL)
        return head;
        Node* mid=midnode(head);
        Node* a=head;
        Node* b=mid->next;
        mid->next=NULL;
        a=mergeSort(a);
        b=mergeSort(b);
         head= mergesorted(a ,b);
        return head;
        
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends
