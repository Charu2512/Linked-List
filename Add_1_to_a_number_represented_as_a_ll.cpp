//Initial template for C++

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
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

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
    Node* reverse(Node* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        Node* smallop=reverse(head->next);
        Node* tail=head->next;
        tail->next=head;
        head->next=NULL;
        return smallop;
    }
    Node* add1(Node* head)
    {
        //if(head==NULL)
        //return head;
        Node* temp=head;
        Node* prev=NULL;
        int carry=1,sum;
        while(temp)
        {
            sum=temp->data+carry;
            if(sum>=10)
            carry=1;
            else
            carry=0;
            sum=sum%10;
            temp->data=sum;
            prev=temp;
            temp=temp->next;
            
        }
        if(carry!=0)
        {
            prev->next=new Node(carry);
            
        }
        return head;
        
    }
    Node* addOne(Node *head) 
    {
        Node* temp=reverse(head);
        Node* res=add1(temp);
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
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends
