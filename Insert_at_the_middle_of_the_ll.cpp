#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    struct Node *next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// function to display the linked list
void display(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout<<endl;
}

Node* insertInMiddle(Node* head, int x);

int main()
{
    int T, n, x;
    cin>>T;
    while(T--)
    {
        cin>> n >> x;
        
        struct Node *head = new Node(x);
        struct Node *tail = head;
        
        for (int i=0; i<n-1; i++)
        {
            cin>>x;
            tail->next = new Node(x);
            tail = tail->next;
        }
        
        cin>> x;
        head = insertInMiddle(head, x);
        display(head);
    }
    return 0;
}
// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// function should insert node at the middle
// of the linked list
Node* insertInMiddle(Node* head, int x)
{
	Node* t=head;
	int size=0;
	
	while(t)
	{
	    size++;
	    t=t->next;
	}
	int p;
	if(size%2==0)
	{
	    p=size/2;
	}
	else
	{
	    p=(size+1)/2;
	}
	Node* temp2=head;
	int j=0;
	while(j<p-1)
	{
	   temp2=temp2->next; 
	   j++;
	}
	Node* ins=new Node(x);

	ins->next=temp2->next;
	temp2->next=ins;
	return head;
	
}
