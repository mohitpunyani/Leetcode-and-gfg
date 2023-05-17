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
    
    TreeNode*solve(TreeNode*root,vector<int>&preorder,int &index,int mini,int maxi)
    {
        
        if(index>=preorder.size())
        {
            return NULL;
        }
        
        if(preorder[index]>maxi || preorder[index]<mini)
        {
            return NULL;
        }
        int value=preorder[index];
        root=new TreeNode(value);
        index++;
        // if(mini<preorder[index]<root->val)
        // {
            root->left=solve(root,preorder,index,mini,root->val);

        // }
        // if(root->val<preorder[index]<maxi){
            root->right=solve(root,preorder,index,root->val,maxi);
        // }
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder)
        
    {
        // optimized approach -> using range concept (my approach)
    
        TreeNode*root=NULL;
        int index=0;
        root=solve(root,preorder,index,INT_MIN,INT_MAX);
        return root;
    }
};