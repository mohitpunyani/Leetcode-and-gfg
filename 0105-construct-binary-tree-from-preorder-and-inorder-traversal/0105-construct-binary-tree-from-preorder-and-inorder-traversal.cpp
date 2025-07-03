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
    int is_find(int element,vector<int>&inorder,vector<int>&preorder,int start,int end)
    {
        for(int i=start;i<=end;i++)
        {
            if(element==inorder[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode*solve(vector<int>&inorder,vector<int>&preorder,int &pre_index,int start,int end)
    {
            if(start>end || pre_index>=inorder.size()){
                return NULL;
            }
            int element=preorder[pre_index];
            TreeNode*root=new TreeNode(preorder[pre_index]);
            int index=is_find(element,inorder,preorder,start,end);
            pre_index+=1; // yeah recursion ke according nahi increase hua previous value hain jo variable ki usme 1 increase
            // ho gaya
            root->left=solve(inorder,preorder,pre_index,start,index-1);
            root->right=solve(inorder,preorder,pre_index,index+1,end);
            return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)  
    {
        int pre_index=0;
        int start=0;
        int end=inorder.size()-1;
        return solve(inorder, preorder,pre_index,start,end);
        
    }
};
