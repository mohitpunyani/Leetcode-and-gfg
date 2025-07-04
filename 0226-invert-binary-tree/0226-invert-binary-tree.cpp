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
      
    // void recursive(TreeNode*root)
    // {
    //     if(root==NULL){
    //         return ;
    //     }
    //     if(root->left==NULL && root->right==NULL)
    //     {
    //         return ;

    //     }
    //     swap(root->left,root->right);
    //     reursive(root->left);
    //     recursive(root->right);
    //     return ;
    // }

    stack<TreeNode*>st;
    void iter(TreeNode*root)
    {
        st.push(root);
        while(!st.empty())
        {
            TreeNode*temp=st.top();
            st.pop();
            if(temp->left!=NULL){
                st.push(temp->left);
            }
            if(temp->right!=NULL){
                st.push(temp->right);
            }
            swap(temp->left,temp->right);
        }

    }
    TreeNode* invertTree(TreeNode* root) 
    {
        // RECURSIVE

        // recursive(root);
        // return root;

        // ITERATIVE
        
        if(root==NULL){
            return NULL;
        }
        iter(root);
        return root;
    }
};