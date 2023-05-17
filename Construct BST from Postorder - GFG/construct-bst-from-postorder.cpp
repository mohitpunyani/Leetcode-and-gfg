//{ Driver Code Starts
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

Node *constructTree (int [], int );

void printInorder (Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
	

}

int main ()
{   
    int t,n;
   scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int post[n];
        for(int i=0;i<n;i++)
        scanf("%d",&post[i]);

    Node* root = constructTree(post, n);

	printInorder(root);
    printf("\n");
}
	return 0;
}

// } Driver Code Ends


/*struct Node
{
	int data;
	Node *left, *right;
};*/


Node*solve(Node*root,int &index,int mini,int maxi,int size,int post[]){
    
    if(index<0)
    {
        return NULL;
    }
    if(post[index]>=maxi or post[index]<=mini)
    {
        return NULL;
        
    }

    int value=post[index];
    root=new Node(value);
    index--;
    root->right=solve(root,index,root->data,maxi,size,post);
    root->left=solve(root,index,mini,root->data,size,post);

    return root;
}
Node *constructTree (int post[], int size)
{
//code here

// similar to the question, construct bst from preorder traversal 

Node*root=NULL;
int index=size-1;
root=solve(root,index,INT_MIN,INT_MAX,size,post);
return root;
}