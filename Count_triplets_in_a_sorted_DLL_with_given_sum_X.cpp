// C++ implementation to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
#include <bits/stdc++.h>

using namespace std;

// structure of node of doubly linked list
struct Node {
	int data;
	struct Node* next, *prev;
};

// function to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
int countPairs(struct Node* head,struct Node* tail,int x)
{ if(head==NULL || head->next==NULL)
  return 0;
  Node* temp1=head;
  Node* temp2=tail;
  bool flag=false;
  
 
  int c=0;
 while(temp1 && temp2 && temp1!=temp2 && temp2->next!=temp1)
 {
  if(temp1->data + temp2->data ==x)
  { c++;
   flag=true;
  temp1=temp1->next;
  temp2=temp2->next;
  }
  else if(temp1->data +temp2->data>x)
    temp2=temp2->prev;
  else if(temp1->data +temp2->data <x)
    temp1=temp1->next;
 }
  if(flag==false)
    return 0;
 return c;
  
}
int countTriplets(struct Node* head, int x)
{
  
  Node* temp1=head;
  Node* temp2=head;
  while(temp2->next)
  {
  temp2=temp2->next;
  }
  int c=0;
 while(temp1->next)
 { int sum=x-temp1->data;
   c+=countPairs(temp1->next,temp2,sum);
   temp1=temp1->next;
 }
  
  return c;
   
  
	
}

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node** head, int data)
{
	// allocate node
	struct Node* temp = new Node();

	// put in the data
	temp->data = data;
	temp->next = temp->prev = NULL;

	if ((*head) == NULL)
		(*head) = temp;
	else {
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

// Driver program to test above
int main()
{
	// start with an empty doubly linked list
	struct Node* head = NULL;

	// insert values in sorted order
	insert(&head, 9);
	insert(&head, 8);
	insert(&head, 6);
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 2);
	insert(&head, 1);

	int x = 18;

	cout << "Count = "
		<< countTriplets(head, x);
	return 0;
}
