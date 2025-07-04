class Solution {
public:
   
    vector<vector<int>>ans;
    // vector<int>temp;
    void solve(TreeNode*root,int targetSum,vector<int>&temp)
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
        solve(root->left,targetSum-root->val,temp);
        solve(root->right,targetSum-root->val,temp);
        temp.pop_back(); // backtrack
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<int>temp;
        solve(root,targetSum,temp);
        return ans;
    }
};