#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
       if(head==NULL || head->next==NULL)
       return head;
       Node* zh=NULL;
       Node* zt=NULL;
       Node* oh=NULL;
       Node* ot=NULL;
       Node* th=NULL;
       Node* tt=NULL;
       Node* temp=head;
       while(temp)
       {
           if(temp->data==0)
           {
               if(zh==NULL)
               {
                   zh=temp;
                   zt=temp;
                   
               }
               else
               {
                   zt->next=temp;
                   zt=zt->next;
               }
           }
           else if(temp->data==1)
           {
               if(oh==NULL)
               {
                   oh=temp;
                   ot=temp;
                   
               }
               else
               {
                   ot->next=temp;
                   ot=ot->next;
               }
           }
        else if(temp->data==2)
           {
               if(th==NULL)
               {
                   th=temp;
                   tt=temp;
                   
               }
               else
               {
                   tt->next=temp;
                   tt=tt->next;
               }
           }
           temp=temp->next;
       }
       
       if(zh)
       {
           if(oh)
           {
               zt->next=oh;
               if(th)
               {
                   ot->next=th;
                   tt->next=NULL;
                   return zh;
               }
               else
               {
                   ot->next=NULL;
                   return zh;
               }
           }
           else
           {
               if(th)
               {
                   zt->next=th;
                   tt->next=NULL;
                   return zh;
               }
               else
               {
                   zt->next=NULL;
                   return zh;
                   
                   
               }
               
           }
           
       }
       else
       {
           
           if(oh)
           {
               
               if(th)
               {
                   ot->next=th;
                   tt->next=NULL;
                   return oh;
               }
               else
               {
                   ot->next=NULL;
                   return oh;
               }
           }
           else
           {
               if(th)
               {
                   
                   tt->next=NULL;
                   return th;
               }
               
               
           }
           
           
       }
       
        
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends
