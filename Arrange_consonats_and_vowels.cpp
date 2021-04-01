#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printlist(Node *head)
{
	if (head==NULL)return;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void append(struct Node** headRef, char data)
{
	struct Node* new_node = new Node(data);
	struct Node *last = *headRef;

	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

// task is to complete this function
struct Node* arrange(Node *head);

int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        char tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            append(&head, tmp);
        }
        head = arrange(head);
        printlist(head);
    }
	return 0;
}

// } Driver Code Ends


/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/
// task is to complete this function
// function should return head to the list after making 
// necessary arrangements
bool isvowel(char data)
{
    if(data=='a' || data=='e' || data=='i' || data=='o' || data=='u')
    return true;
    return false;
}
struct Node* arrange(Node *head)
{
  if(head==NULL || head->next==NULL)
  return head;
  Node* ch=NULL;
  Node* ct=NULL;
  Node* vh=NULL;
  Node* vt=NULL;
  Node* root=head;
  while(root)
  {
      if(isvowel(root->data))
      {
          if(vh==NULL)
          {
              vh=root;
              vt=root;
          }
          else
          {
              vt->next=root;
              vt=vt->next;
          }
      }
      
      if(!(isvowel(root->data)))
      {
          if(ch==NULL)
          {
              ch=root;
              ct=root;
          }
          else
          {
              ct->next=root;
              ct=ct->next;
          }
      }
      root=root->next;
  }
  if(ch==NULL)
  {
      vt->next=NULL;
      return vh;
  }
  if(vh==NULL)
  {
      ct->next=NULL;
      return ch;
  }
  vt->next=ch;
  ct->next=NULL;
  
  return vh;
  
}
