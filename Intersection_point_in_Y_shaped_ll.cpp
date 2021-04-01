#include<iostream>
#include<stdio.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{Node* temp1=head1;
    Node* temp2=head2;
    int c1=0;
    while(temp1)
    {
        c1++;
        temp1=temp1->next;
    }
    int c2=0;
    while(temp2)
    {
        c2++;
        temp2=temp2->next;
    }
    if(c1>c2)
    {   Node* te1=head1;
        Node* te2=head2;
        int d=c1-c2;
        int j=0;
        while(j<d)
        {   
            te1=te1->next;
            j++;
        }
        while(te1!=NULL && te2!=NULL)
        {
            if(te1==te2)
            {
                return te1->data;
            }
            te1=te1->next;
            te2=te2->next;
        }
        
    }
     else if(c1<=c2)
    {   Node* te1=head1;
        Node* te2=head2;
        int d=c2-c1;
        int j=0;
        while(j<d)
        {   
            te2=te2->next;
            j++;
        }
        while(te1!=NULL && te2!=NULL)
        {
            if(te1==te2)
            {
                return te1->data;
            }
            te1=te1->next;
            te2=te2->next;
        }
        
    }
        return -1;
}
    



