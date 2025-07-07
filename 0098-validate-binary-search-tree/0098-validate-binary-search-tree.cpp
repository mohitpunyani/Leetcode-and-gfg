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
    bool solve(TreeNode*root,long long int min,long long int max)
    {
        if(root==NULL)
        {
            return true;
        }

    if(root->val>min && root->val<max)
    {
        bool left=solve(root->left,min,root->val);
        bool right=solve(root->right,root->val,max);
        return left && right;
    }
    else{
        return false;
    }
}
public:
    bool isValidBST(TreeNode* root) 
    {
        // solve using range concept by love babbar.
        
        return solve(root,-21474836470,21474836470);
      
    }
    
};