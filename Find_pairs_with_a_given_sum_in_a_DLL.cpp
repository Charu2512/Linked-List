/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// C++ program to find a pair with given sum x.
#include<bits/stdc++.h>
using namespace std;

// structure of node of doubly linked list
struct Node
{
	int data;
	struct Node *next, *prev;
};

// Function to find pair whose sum equal to given value x.
void pairSum(struct Node *head, int x)
{
  Node* temp1=head;
  Node* temp2=head;
  bool flag=false;
  while(temp2->next!=NULL)
  {
  temp2=temp2->next;}
  while(temp1 && temp2 && temp1!=temp2 && temp2->next!=temp1)
  {
    if(temp1->data+ temp2->data ==x)
    {
      flag=true;
      cout<<temp1->data<<" "<<temp2->data;
      cout<<endl;
      temp1=temp1->next;
      temp2=temp2->prev;
      
    }
    else if( temp1->data +temp2->data <x)
      temp1=temp1->next;
    else if(temp1->data +temp2->data >x)
      temp2=temp2->prev;
   }
  if(flag==false)
    cout<<"Pair not found"<<endl;
}

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node **head, int data)
{
	struct Node *temp = new Node;
	temp->data = data;
	temp->next = temp->prev = NULL;
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

// Driver program
int main()
{
	struct Node *head = NULL;
	insert(&head, 9);
	insert(&head, 8);
	insert(&head, 6);
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 2);
	insert(&head, 1);
	int x = 10;

	pairSum(head, x);

	return 0;
}
