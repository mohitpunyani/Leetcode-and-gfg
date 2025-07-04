class Solution {
public:
    void solution(TreeNode* root,vector<vector<int>>&ans,vector<int>&path,int k){
        if(!root) return ;

        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL && k-root->val == 0){ 
            ans.push_back(path);
        }
        // if(root->left) 
        solution(root->left,ans,path,k - root->val);
        // if(root->right) 
        solution(root->right,ans,path,k - root->val);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int k) {
        vector<vector<int>> ans;
        vector<int>path;
        solution(root,ans,path,k);
        return ans;
    }
};