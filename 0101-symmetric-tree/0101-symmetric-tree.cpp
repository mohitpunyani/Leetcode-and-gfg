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
    void invert(TreeNode*root)
    {
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            return ;
        }
        swap(root->left,root->right);
        invert(root->left);
        invert(root->right);
        return ;
    }
    bool recur(TreeNode*p,TreeNode*q)
    {
        if(p==NULL && q!=NULL){
            return false;
        }
        if(p!=NULL && q==NULL){
            return false;
        }
        if(p==NULL && q==NULL){
            return true;
        }
        if(p->val!=q->val){
            return false;
        }     
        bool left=recur(p->left,q->left);
        bool right=recur(p->right,q->right);
        if(left && right)
        {
            return true;
        }
        else{
            return false;
        }

    }
    bool isSymmetric(TreeNode* root) 
    {
        // RECURSIVE
        // first invert whole left tree and then match with left and right tree
        invert(root->left);
        return recur(root->left, root->right);

        
    }
};