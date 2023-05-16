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
  
  TNode* convert_into_bst(vector<int>&nums,int low,int high,TNode* root)
{
    
    if(low>high)
    {
        return NULL; 
    }
    int mid=low+(high-low+1)/2;
    root=new TNode(nums[mid]);
    
    root->left=convert_into_bst(nums,low,mid-1,root);
    
    root->right=convert_into_bst(nums,mid+1,high,root);
    
    return root;
}

    TNode* sortedListToBST(LNode *head)
    {
        //code here
        
        // similar to the (convert array into bst )
        
        // first convert linked list into array
        
        vector<int>nums;
        
        LNode*temp=head;
        while(temp!=NULL)
        {
            nums.push_back(temp->data);
            temp=temp->next;
        }
        
        int low=0;
        int high=nums.size()-1;
        TNode*root=NULL;
        root=convert_into_bst(nums,low,high,root);
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