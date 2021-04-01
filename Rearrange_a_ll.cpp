#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};



 // } Driver Code Ends
/* Node structure

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
    public:
    Node *rearrangeEvenOdd(Node *head)
    {
      if(head==NULL || head->next==NULL)
      return head;
      Node* temp=head;
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
          c++;
          temp=temp->next;
          
          
      }
      l1t->next=NULL;
      l2t->next=NULL;
      l1t->next=l2h;
      
      return l1h;
      
      
    }
};


// { Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {   
                head = temp = new Node(l); 
                
            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }
        Solution ob;
        head = ob.rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends
