#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
  }  
  cout<<"\n";
} 

Node *insertAtBegining(Node *head, int newData);
Node *insertAtEnd(Node *head, int newData);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        struct Node *head = NULL;
        for (int i = 0; i < n; ++i)
        {
            int data, indicator;
            cin>>data;
            cin>>indicator;
            if(indicator)
                head = insertAtEnd(head, data); 
            else
                head = insertAtBegining(head, data);
        }
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends


/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

// function inserts the data in front of the list
Node *insertAtBegining(Node *head, int newData) {
   // Your code here
   Node* temp=new Node(newData);
   temp->next=head;
   head=temp;
   return head;
}


// function appends the data at the end of the list
Node *insertAtEnd(Node *head, int newData)  {
     Node* temp=new Node(newData);
     Node* temp1=head;
     if(temp1==NULL)
     {
         return temp;
     }
     while(temp1->next)
     {
         temp1=temp1->next;
     }
     temp1->next=temp;
     return head;
   
   
}
