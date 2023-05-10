//{ Driver Code Starts
#include <bits/stdc++.h>
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
    Node *zigZag(Node* head)
    {
     // your code goes here
     
    //   similar like zig zag travesal of array
    
    // play with even and odd indexes

         // your code goes here

     if(head->next==NULL)

        return head;

     Node *curr=head;

     int count=1;

     while(curr->next)

     {

         if(count%2!=0)

         {

             if(curr->data>curr->next->data)

                swap(curr->data,curr->next->data);

            count=0;

         }

         else if(count==0)

         {

             if(curr->data<curr->next->data)

                swap (curr->data,curr->next->data);

            count=1;

         }

         curr=curr->next;

     }

     return head;

     

    
    }
};

//{ Driver Code Starts.


int main() {
	// your code goes here
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
				temp=temp->next;
			}
		}
		Solution ob;
		Node *ans = ob.zigZag(head);
		print(ans);
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends