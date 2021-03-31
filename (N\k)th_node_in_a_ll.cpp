#include<bits/stdc++.h>
using namespace std;

int fractional_node(struct Node* head,int k);

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* ptr,*start = NULL,*ptr1;
        int n,i;
        cin>>n;
        
        for(i=0;i<n;i++)
        {
            int value;
            cin>>value;
            
            ptr=new Node(value);
            
            if(start==NULL)
            {
                start=ptr;
                ptr1=ptr;
            }
            else
            {
                ptr1->next=ptr;
                ptr1=ptr1->next;
            }
        }
        ptr1->next=NULL;
        int k;
        cin>>k;
        int p = fractional_node(start,k);
        cout<<p<<endl;
    }
}
// } Driver Code Ends


/*The structure of the node is
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
int fractional_node(struct Node *head, int k)
{
    Node* temp=head;
    double size=0;
    while(temp)
    {
        size++;
        temp=temp->next;
    }
     double p=ceil(size/k);
    Node* temp1=head;
    int j=0;
    while(j<p-1)
    {
        temp1=temp1->next;
        j++;
    }
    int res=temp1->data;
    return res;
    
}
