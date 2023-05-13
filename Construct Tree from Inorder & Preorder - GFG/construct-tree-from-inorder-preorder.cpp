//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    int findposition(int in[],int element,int inorder_starting_index,int inorder_ending_index){
        for(int i=inorder_starting_index;i<=inorder_ending_index;i++){
            if(in[i]==element){
                return i;
            }
        }
        return -1;
    }
    Node* solve(int in[],int pre[],int &preorder_index,int inorder_starting_index,int inorder_ending_index,int n)
    {
        
        // base case
        if(preorder_index>=n){
            return NULL;
        }
        if(inorder_starting_index > inorder_ending_index)
        {
            return NULL;
            
        }
        int element=pre[preorder_index];
        
        preorder_index++;
        
        Node*root=new Node(element);
        
        int position=findposition(in,element,inorder_starting_index,inorder_ending_index);
        
        root->left=solve(in,pre,preorder_index,inorder_starting_index,position-1,n);
        
        root->right=solve(in,pre,preorder_index,position+1,inorder_ending_index,n);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        
        // sara khel  recursion ka hai
        
        // in -> inorder index
        //  pre -> preorder index
        
        // IMPORTANT POINTS
        
        // 1. TAKE INDEX OF PREORDER ARRAY AND FIND INTO INORDER ARRAY AND THEN WE GETTING A NEW PROBLEM
        
        
        // AND GETTING A NEW SUB PROBLEM
        int preorder_index=0;
        
        Node*ans=solve(in,pre,preorder_index,0,n-1,n);
        return ans;
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
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends