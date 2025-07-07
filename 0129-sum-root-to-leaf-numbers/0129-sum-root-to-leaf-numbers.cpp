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
    
    int sum=0;

    int ans=0;
    void solve(TreeNode*root)
    {
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL)
        {
            sum=sum*10+root->val;
            ans=ans+sum;
            sum=sum/10; // backtrack;
            return ;
        }
        sum=sum*10+root->val;
        solve(root->left);
        solve(root->right);
        sum=sum/10; // backtrack;
        return ;

    }
    int sumNumbers(TreeNode* root)
    {
        solve(root);
        return ans;
        
    }
};




// class Solution {
// public:
    
//     int sum=0;

//     int ans=0;
//     void solve(TreeNode*root)
//     {
//         if(root==NULL){
//             return ;
//         }
//         if(root->left==NULL && root->right==NULL)
//         {
//             sum=sum*10+root->val;
//             ans=ans+sum;
//             sum=sum/10;
//             return ;
//         }
//         sum=sum*10+root->val;
//         solve(root->left);
//         solve(root->right);
//         sum=sum/10;
//         return ;

//     }
//     int sumNumbers(TreeNode* root)
//     {
//         solve(root);
//         return ans;
        
//     }
// };