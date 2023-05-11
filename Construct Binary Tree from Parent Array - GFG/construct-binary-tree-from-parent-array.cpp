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
    
    // searching the index of parent my parent
    
    // binary tree is a tree which have less than or equal to two children
    
    vector<int>v;
    
    // this is my approach 
 
 // NOTE-> KABHI BAAP BHI BACHE THA THINKING (and play with index)
 
//  NOTE-> KABHI BACHE BHI BAAP BANAGE

 vector<int> find_child_of_parent(int parent[],int N,int baap)
 {
         // binary tree is a tree which have less than or equal to two children
    
    vector<int>child(2,-1);
     
     int t=0;
     for(int beta=0;beta<N;beta++)
     {
         if(parent[beta]==baap)
         {
             child[t]=beta;
             t++;
             
         }
     }
     return child;
 }
 //
  Node*solve(Node*root,int parent [],int N,int baap )
  {
      // we know that every parent has atmost two child
      
      //  NOTE -> baap ke bache doondo.(IMP)
      
      if(baap==-1)
      {
          return NULL;
      }
      root=new Node(baap);
      vector<int>child=find_child_of_parent(parent,N,baap);
      
      // NOTE -> aur JAISE HI BACHE MILE AB BACHE baap ban jayega (IMP)
      
      root->left=solve(root->left,parent,N,child[0]);
      root->right=solve(root->right,parent,N,child[1]);
      return root;
  }
    Node *createTree(int parent[], int N)
    {
        // Your code here
        // 1. recursive approach  that comes in mind
      
    //   Node*root=NULL;
    //   int baap;
    //   for(int i=0;i<N;i++)
    //   {
    //       if(parent[i]==-1){
    //           baap=i;
    //           break;
    //       }
          
    //   }
      
      // idx will be our parent
      
      
      //recursive approach 
      
      
    //   root=solve(root,parent,N,baap);
    //   return root;
    
    // 2 iterative approach using queue
    
    // HAR EK PARENT KE CORRESPONDING BACHE STORE KAR LIYE
    
    
    // NOTE -> HERE VALUES OF THE ARRAY ARE THE PARENT AND INDEXES OF THE ARRAY ARE THE CHILDREN
    
        unordered_map<int,pair<Node*,Node*>>mp;
        
        // in map keys are always unique
        
        for(int i=0;i<N;i++){
            if(mp.find(parent[i])==mp.end())
            {
                mp[parent[i]].first=new Node(i);
                
            }
            else{
                mp[parent[i]].second=new Node(i);
            }
        }
        queue<Node*>q;
        
        Node*root=mp[-1].first;
        Node*copyroot=root;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            
            while(size--){
                
            root=q.front();
            
            q.pop();
            
            // ab  baap (root) ke corresponding jo bache hai inko  jod do.
            
            root->left=mp[root->data].first;
            root->right=mp[root->data].second;
            if(root->left!=NULL){
                q.push(root->left);
            }
            if(root->right!=NULL){
                q.push(root->right);
            }
        }
        }
        return copyroot;
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