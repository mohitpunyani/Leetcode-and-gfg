//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
};

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new Node(new_data);
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		cout<<temp->data<<' ';
		temp = temp->next;
	}
	cout<<'\n';
}

void mergeList(struct Node **head1, struct Node **head2);

// Driver program to test above functions
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n1, n2, tmp;
        struct Node *a = NULL;
        struct Node *b = NULL;
        cin>>n1;
        while(n1--){
            cin>>tmp;
            push(&a, tmp);
        }
        cin>>n2;
        while(n2--){
            cin>>tmp;
            push(&b, tmp);
        }
        mergeList(&a, &b);
        printList(a);
        printList(b);
    }
	return 0;
}

// } Driver Code Ends


/*
structure of the node of the linked list is
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
// complete this function
void mergeList(struct Node **p, struct Node **q)
{
     // Code here
     
     // first reverse both the linked list
     
    //  Node*curr1=*p;
    //  Node*curr2=*q;
     
    //  // linked list are already given in reverse order
     
    //  while(curr1!=NULL && curr2!=NULL)
    //  {
    //      Node*Next1=curr1->next;
    //      Node*Next2=curr2->next;
    //      curr1->next=curr2;
    //      curr2->next=Next1;
    //      curr1=curr1->next;
    //      curr2=curr2->next;
    //  }
    // *q=curr2;
// }
    Node *curr1=*p,*curr2=*q;
Node *c1=curr1;
while(curr1!=NULL&&curr2!=NULL)
{
Node *temp1=curr1->next;
Node *temp2=curr2->next;
curr1->next=curr2;
curr2->next=temp1;
curr1=temp1;
curr2=temp2;
}
*p=c1;
*q=curr2;
}
