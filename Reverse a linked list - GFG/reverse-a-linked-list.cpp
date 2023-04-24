//{ Driver Code Starts
//Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:
    //Function to reverse a linked list.
    void rev(Node*&head,Node*prev,Node*curr)
{
    if(curr==NULL)
      {
          head=prev;
          return ;
      }
        
        Node*temp=curr->next;
        rev(head,curr,temp);
        curr->next=prev;
        return ;

}
    
    // IT'S VERY IMPORTANT TO CONVERT ITERATIVE INTO RECUSIVE
    struct Node* reverseList(struct Node *head)
    {
        // code here
        
        
        // iterative
        
        // if(head->next==NULL){
        //     return head;
        // }
        // Node*prev=NULL;
        // Node*curr=head;
        // while(curr!=NULL){
        //     Node*temp=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=temp;
        // }

        // return prev;
        
        
        // recursive
        Node*prev=NULL;
        Node*curr=head;
        rev(head,prev,curr);
        return head;
    }
    
};
    


//{ Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends