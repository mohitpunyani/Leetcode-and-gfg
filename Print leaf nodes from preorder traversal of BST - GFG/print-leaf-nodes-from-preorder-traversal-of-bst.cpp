//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// solve using creation of tree

class Node{
    public:
    
    int data;
    Node*left;
    Node*right;
    
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
class Solution {
  public:
  
  vector<int>ans;
  Node *make_tree_through_preorder(Node*root,int &index,int arr[],int &size,int min ,int max){
      
      if(index>=size){
          return NULL;
      }
      
      if(min>=arr[index] || arr[index]>=max){
          return NULL;
      }
      
      root=new Node(arr[index]);
      index+=1;
      root->left=make_tree_through_preorder(root,index,arr,size,min,root->data);
      root->right=make_tree_through_preorder(root,index,arr,size,root->data,max);
      
      if(root->left==NULL && root->right==NULL){
          ans.push_back(root->data);
      }
      return root;
  }
  
 
    vector<int> leafNodes(int arr[],int N) {
        // code here
        
        // make a tree
        
        
        int indx=0;
        
        
        Node* root=NULL;
        
        root=make_tree_through_preorder(root,indx,arr,N,INT_MIN,INT_MAX);
        
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
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends