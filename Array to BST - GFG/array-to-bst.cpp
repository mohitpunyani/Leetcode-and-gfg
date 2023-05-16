//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// create a linked list node class

class Node
{
    public :
    
    int data;
    Node*left;
    Node*right;
    
    Node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

class Solution {
public:

Node*convert_into_bst(vector<int>&nums,int low,int high,Node* root)
{
    
    if(low>high)
    {
        return NULL; 
    }
    int mid=low+(high-low)/2;
    
    root=new Node(nums[mid]);
    
    root->left=convert_into_bst(nums,low,mid-1,root);
    
    root->right=convert_into_bst(nums,mid+1,high,root);
    
    return root;
}

void preorder(Node*root,vector<int>&ans)
{
    if(root==NULL){
        return ;
    }
    
    ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);
    return ;
}
    vector<int> sortedArrayToBST(vector<int>& nums) 
    {
        // Code here
        
        // very easy question 
        
        // my approach (using binary search)
        
        //  create bst and find its preorder traversal
        
        int low=0;
        int high=nums.size()-1;
        Node*root=NULL;
        root=convert_into_bst(nums,low,high,root);
        
        vector<int>ans;
        preorder(root,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends