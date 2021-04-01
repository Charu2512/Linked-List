#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


 // } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node* reverse(Node* temp)
    {
        if(temp==NULL || temp->next==NULL)
        return temp;
        Node* smallop=reverse(temp->next);
        Node* tail=temp->next;
        tail->next=temp;
        temp->next=NULL;
        return smallop;
    }
    void rearrange(struct Node *odd)
    {   if(odd==NULL || odd->next==NULL)
    return ;
        Node* temp=odd;
        Node* l1h=NULL;
        Node* l1t=NULL;
        Node* l2h=NULL;
        Node* l2t=NULL;
        int c=1;
        while(temp)
        {
            if(c%2!=0)
            {
                if(l1h==NULL)
                {
                    l1h=temp;
                    l1t=temp;
                }
                else
                {
                    l1t->next=temp;
                    l1t=l1t->next;
                }
            }
            if(c%2==0)
            {
                if(l2h==NULL)
                {
                    l2h=temp;
                    l2t=temp;
                }
                else
                {
                    l2t->next=temp;
                    l2t=l2t->next;
                }
            }
            temp=temp->next;
            c++;
            
        }
    l1t->next=NULL;
    l2t->next=NULL;
        Node* res=reverse(l2h);
        l1t->next=res;
        odd=l1h;
        
    }
};



// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}
  // } Driver Code Ends
