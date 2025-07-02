/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 */

// @lc code=start
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
queue<TreeNode*>q;

vector<vector<int>>ans;

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        // starting level is 0 or even level , reverse nodes at odd level
        
        if(root==NULL){
            return {};
        }
        q.push(root);
        int level=0;// 0 for even and 1 for odd
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>temp;
            while(sz--)
            {
                TreeNode*node=q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            if(level%2!=0){
                // level is 1 means odd so reverse temp and then push to ans
                reverse(temp.begin(),temp.end());
            }
            level=!level;
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end

