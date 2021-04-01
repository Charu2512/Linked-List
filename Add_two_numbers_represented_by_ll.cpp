
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
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
    Node* add2(Node* h1, Node* h2)
    {
        Node* temp1=h1;
        Node* temp2=h2;
        Node* temp=NULL;
        
        Node* resh=NULL;
        Node* rest=NULL;
        int carry=0,sum;
        Node* prev1=NULL;
        Node* prev2=NULL;
        while(temp1 || temp2)
        {
            sum=(temp1?temp1->data:0)+(temp2?temp2->data:0)+carry;
            if(sum>=10)
            carry=1;
            else
            carry=0;
            sum=sum%10;
            temp=new Node(sum);
            if(resh==NULL)
            {resh=temp;
            rest=temp;
            }
            else{
            rest->next=temp;
            rest=rest->next;
            }
            if(temp1)
            temp1=temp1->next;
            if(temp2)
            temp2=temp2->next;
            
        }
        if(carry==1)
        {
           if(carry>0)
           rest->next=new Node(carry);
            
        }
        return resh;
    }
        
    
    
    struct Node* addTwoLists(struct Node* h1, struct Node* h2)
    {
        Node* t1=reverse(h1);
        Node* t2=reverse(h2);
        Node* res=add2(t1,t2);
        return reverse(res);
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends
