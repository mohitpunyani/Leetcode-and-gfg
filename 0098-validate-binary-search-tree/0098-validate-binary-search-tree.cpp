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
    bool solve(TreeNode*root,long long int mn,long long int mx)
    {
        if(root==NULL)
        {
            return true;
        }

        if(root->val<=mn or root->val>=mx ){
            return false;
        }
        else{
            bool left=solve(root->left,mn,root->val);
            bool right=solve(root->right,root->val,mx);
            if(left && right){
                return true;
            }
            else{
                return false;
            }
        }
}
public:
    bool isValidBST(TreeNode* root) 
    {
        // solve using range concept by love babbar.
        
        long long int mn=LONG_MIN;
        long long int mx=LONG_MAX;
        return solve(root,mn,mx);
      
    }
    
};