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
        // return recur(root->left,root->right);

        // follow iteration approach 

        if(root==NULL){
            return true;
        }
        queue<TreeNode*>q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty())
        {
            TreeNode*node1=q.front();
            q.pop();
            TreeNode*node2=q.front();
            q.pop();
            if(node1==NULL && node2==NULL){
                continue;
            }
            if(node1==NULL && node2!=NULL){
                return false;
            }
            if(node1!=NULL && node2==NULL){
                return false;
            }
            if(node1->val!=node2->val)
            {
                return false;
            }
            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }
        return true;
        
        
    }
};