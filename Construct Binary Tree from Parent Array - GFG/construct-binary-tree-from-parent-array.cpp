//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector <int> &v)
{
    sort( v.begin() , v.end() );
    for( int i=0 ; i<v.size() ; i++ )
        cout<< v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root)
{
    vector <int> v;
    queue <Node*> q;
    
    q.push(root);
    
    Node* next_row = NULL;
    
    while(!q.empty())
    {
        Node* n = q.front();
        q.pop();
        
        if(n==next_row)
        {
            sort_and_print(v);
            next_row = NULL;
        }
        
        v.push_back(n->data);
        
        if(n->left)
        {
            q.push(n->left);
            if(next_row == NULL) next_row = n->left;
        }
        
        if(n->right)
        {
            q.push(n->right);
            if(next_row == NULL) next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node *createTree(int parent[], int n);

/* Driver program to test above function*/


// } Driver Code Ends
/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution{
  public:
    //Function to construct binary tree from parent array.
    
    // searching the index of parent
  vector<int> search(int a[],int n,int data){
        vector<int> v(2,-1);
        int t = 0;
        for(int i=0;i<n;i++)
            if(a[i] == data)
                v[t++] = i;
        return v;
    }
    Node* helper(int p[],int n,int idx){
        if(idx == -1)
            return NULL;
        
        Node* node = new Node(idx);
        vector<int> v = search(p,n,idx);
        
        node->left = helper(p,n,v[0]);
        node->right = helper(p,n,v[1]);
        
        return node;
    }
    Node *createTree(int parent[], int N)
    {
        // Your code here
        // 1. recursive approach  that comes
      
        
         Node* root = NULL;
        int idx = -1;
        for(int i=0;i<N;i++)
            if(parent[i] == -1)
                idx = i;
        root = helper(parent,N,idx);
        return root;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>> n;
        int a[n];
        for( int i=0 ; i<n ; i++ )
            cin>> a[i];
            
        Solution ob;
        
        Node *res = ob.createTree(a,n);
        
        printLevelOrder(res);
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends