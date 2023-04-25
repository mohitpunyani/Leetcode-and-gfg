//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    
    node* rev(node*head,int count,int k)
    {
        
        
        node*prev=NULL;
        node*curr=head;
        while(curr!=NULL && count<=k)
        {

            node*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            count++;
        }
        
        if(curr!=NULL)
        {
            // curr banega naya head;
            // IMP: - recursive call me arguments par focus kiya kar
            
             head->next=rev(curr,1,k);
        }
        if(curr==NULL && count==k){
            return prev;
        }
        else{
            return prev;
        }
        
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        
        int count=1;
        // now prev is our new head;
        
        node*ans=rev(head,count,k);
        return ans;
        
        
        
        
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends