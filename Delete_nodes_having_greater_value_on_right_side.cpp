#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        if(head==NULL || head->next==NULL)
        return head;
        Node* smallop=compute(head->next);
        if(smallop->data> head->data)
        return smallop;
        else
        {
            head->next=smallop;
            return head;
        }
        
    /* This solutuin is showing error for one test case while submitting in GFG.
    if(head==NULL || head->next==NULL)
    return head;
    Node* temph=NULL;
    Node* tempt=NULL;
    Node* root=head;
    while(root && root->next)
    {
        if(root->next &&  root->data > root->next->data)
        {
            if(temph==NULL)
            {
                temph=root;
                tempt=root;
            }
            else
            {
                tempt->next=root;
                tempt=tempt->next;
            }
        }
        root=root->next;
    }
    tempt->next=root;
    tempt=tempt->next;
    tempt->next=NULL;
    return temph;*/
    }
    
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends
