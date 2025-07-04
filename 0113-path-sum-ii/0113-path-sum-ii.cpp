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
   
    vector<vector<int>>ans;
    vector<int>temp;
    void solve(TreeNode*root,int targetSum)
    {
        if(root==NULL)
        {
            return ;
        }
        if(root->left==NULL && root->right==NULL && targetSum-root->val==0)
        {
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return ;
        }
        temp.push_back(root->val);
        solve(root->left,targetSum-root->val);
        // temp.pop_back();
        solve(root->right,targetSum-root->val);
        temp.pop_back();
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        solve(root,targetSum);
        return ans;
    }
};