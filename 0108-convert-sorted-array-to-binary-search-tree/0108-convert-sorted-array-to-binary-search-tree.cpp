/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode*&root,vector<int>&nums,int low,int high)
    {
        if(low>high)
        {
            return NULL;
        }
        int mid=low+(high-low)/2;
        int element=nums[mid];
        root=new TreeNode(element);
        root->left=solve(root->left,nums,low,mid-1);
        root->right=solve(root->right,nums,mid+1,high);
        return root;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {

        
        int low=0;
        int high=nums.size()-1;
        int n=nums.size();
        TreeNode*root=NULL;
        return solve(root,nums,0,high);
        
        
    }
};