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
    bool solve(TreeNode*root,int targetSum)
    { 
        if(root == NULL)
        {
            return false;
        }
        if(root->left == NULL && root->right == NULL &&  targetSum == root->val)
        {
            return true;  // RETURN TRUE WHEN WE REACHED TO THE LEAVE NODE
        }
        
        bool left=solve(root->left,targetSum-root->val);
        bool right=solve(root->right,targetSum-root->val);
        return left or right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root==NULL){
            return false;
        }
        return solve(root,targetSum);
    }
};