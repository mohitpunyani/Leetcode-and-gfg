//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


// } Driver Code Ends
//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  public:
  
  // find middle element in linked list  using slow and fast pointer concept 
  
  LNode* middle(LNode* head){
      
      LNode*slow=head;
      LNode*fast=head;
      LNode*prev=head;
      while(fast!=NULL && fast->next!=NULL)
      {
          prev=slow;
          fast=fast->next;
          slow=slow->next;
          if(fast->next!=NULL){
              fast=fast->next;
          }
      }
    //   if(prev){
        //   
     
     prev->next=NULL;
    //   }
      return slow;
  }
  
  TNode* convert_into_bst(LNode*head,TNode*root)
{
    
         if(head==NULL)return NULL;
         if(head->next==NULL){
           TNode* newnode=new TNode(head->data);
           return newnode;
       }
    LNode* mid=middle(head);
    
    root=new TNode(mid->data);
    
    root->left=convert_into_bst(head,root);
    
    root->right=convert_into_bst(mid->next,root);
    
    return root;
}

    TNode* sortedListToBST(LNode *head)
    {
        
        
        //  APPROACH 2 -> WITHOUT CONVERTING INTO ARRAY
        
        TNode*root=NULL;
        root=convert_into_bst(head,root);
        return root;
        
        
    }
};



//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}

// } Driver Code Ends