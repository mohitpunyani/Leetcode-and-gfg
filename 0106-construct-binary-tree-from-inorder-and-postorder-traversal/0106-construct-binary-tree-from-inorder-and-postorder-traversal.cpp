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

   int is_find(int element,vector<int>&inorder,int start,int end)
   {
        for(int i=start;i<=end;i++)
        {
            if(element==inorder[i])
            {
                return i;
            }
        }
        return -1;
   }

    TreeNode*solve(vector<int>&inorder, vector<int>&postorder, int &post_index,int start,int end)
    { 
        if(post_index<0 || start>end){
            return NULL;
        }

        int element=postorder[post_index];
        TreeNode*root=new TreeNode(element);
        int index=is_find(element, inorder, start,end);
        post_index-=1;
        root->right=solve(inorder,postorder,post_index,index+1,end);
        root->left=solve(inorder,postorder,post_index,start,index-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int post_index=postorder.size()-1;
        int start=0;
        int end=inorder.size()-1;
        return solve(inorder,postorder,post_index,start,end);
        
    }
};