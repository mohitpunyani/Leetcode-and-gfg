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
    // bool invert_follow_recur(TreeNode*p,TreeNode*q)
    // {
    //     if(p==NULL && q!=NULL){
    //         return false;
    //     }
    //     if(p!=NULL && q==NULL){
    //         return false;
    //     }
    //     if(p==NULL && q==NULL){
    //         return true;
    //     }
    //     if(p->val!=q->val){
    //         return false;
    //     }     
    //     bool left=invert_follow_recur(p->left,q->left);
    //     bool right=invert_follow_recur(p->right,q->right);
    //     if(left && right)
    //     {
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }

    // }


    // WITHOUT INVERT DIRECT RECURSION

    bool recur(TreeNode*p,TreeNode*q){
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
        bool left=recur(p->left,q->right);
        bool right=recur(p->right,q->left);
        if(left && right){
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
        
        // invert(root->left);
        // return invert_follow_recur(root->left, root->right);

        // WITHOUT INVERT THE TREE , DIRECT RECURSION
        return recur(root->left,root->right);
        
    }
};