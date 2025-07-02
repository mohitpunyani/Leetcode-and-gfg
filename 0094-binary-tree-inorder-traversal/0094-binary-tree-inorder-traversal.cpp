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
vector<int>ans;
stack<TreeNode*>st;

void iter(TreeNode*root){

    TreeNode*curr=root;
    while(curr!=NULL){
        st.push(curr);
        curr=curr->left; 
    }
    while(!st.empty()){
        curr=st.top();
        st.pop();
        ans.push_back(curr->val);
        curr=curr->right;
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
    }
    return ;
}
// void recur(TreeNode*root)
// {
//     if(root==NULL){
//         return ;
//     }
//     recur(root->left);
//     ans.push_back(root->val);
//     recur(root->right);
//     return ;
// }

    vector<int> inorderTraversal(TreeNode* root) 
    {
        // RECURSIVE

        // recur(root);
        // return ans;

        // ITERATIVE (DFS , so we have to use stack)
        
        iter(root);
        return ans;

    }
};