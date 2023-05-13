//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.

int findposition(int in[],int element,int inorder_starting_index,int inorder_ending_index){
    
    for(int i=inorder_starting_index;i<=inorder_ending_index;i++){
        if(in[i]==element)
        {
            return i;
        }
    }
    return -1;
}
Node* solve(int in[],int post[],int &postorder_index,int inorder_starting_index,int inorder_ending_index,int n)
  {
    
    if(postorder_index<0)
    {
        return NULL;
        
    }
    if(inorder_starting_index > inorder_ending_index){
        return NULL;
    }
    int element=post[postorder_index];
    
    postorder_index--;
    
    Node*root=new Node(element);
    
    int position=findposition(in,element,inorder_starting_index,inorder_ending_index);
    
    // root->left=solve(in,post,postorder_index,inorder_starting_index,position-1,n);
    root->right=solve(in,post,postorder_index,position+1,inorder_ending_index,n);
    
     root->left=solve(in,post,postorder_index,inorder_starting_index,position-1,n);
    
    return root;
}
Node *buildTree(int in[], int post[],int n)
{

    // Your code here
    
    // same question and apply same approach , observe index carefully 
    
    int postorder_index=n-1;
    Node*ans=solve(in,post,postorder_index,0,n-1,n);
    return ans;
    
}
